#include <bits/stdc++.h>
using namespace std;


/*

Problem Statement:

Ships are aligned in layers, with following conditions:
Each ship has value(v)
Each ship in a layer is followed by [v^2+1]%M ships,with values from 0 to ([v^2+1]%M)-1
The first ship has value v=2
M is constant given as argument
Find The Total number of ships %M in all layers
Ex:
L=1
M=4
Output:1 //One layer thus only 1 ship




*/


int find(int L,int m){
	queue <pair<int,int>> q;
	q.push(make_pair(2,0));
	int count = 0;
	pair <int,int> p;

	while(!q.empty()){
		p=q.front();
		q.push();

		count = (count+1)%m;
		if(p.second+1 < L){
			int temp = ((p.first * p.first)+1)%m;

			for(int i = 0;i<temp;i++){
				q.push(make_pair(i, p.second + 1));
			}
		}
	}
	return count;
}


int main(){

	int L,m;
	cin>>L>>m;

	cout<<find(L,m)<<endl;

	return 0;

}