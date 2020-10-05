// Given three points we have to count the number of integral points inside a traingle formed by the three points.

// Using PICK's THEOREM

#include <bits/stdc++.h>
using namespace std;


int gcd(int a,int b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int count_on_edges(int x1,int y1,int x2,int y2){

	//Checking if Parallel to x
	if(x1 == x2)
		return abs(y1-y2)-1;
	if(y1 == y2)
		return abs(x1-x2)-1;
	return gcd(abs(x1-x2),abs(y1-y2))-1;

}

int count(int x1,int y1,int x2,int y2,int x3,int y3){
	int area_multiplied_by_2=abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
	// +3 for three vertices
	int no_of_integral_points_on_edges=count_on_edges(x1,y1,x2,y2)+count_on_edges(x2,y2,x3,y3)+count_on_edges(x1,y1,x3,y3)+3;
	return (area_multiplied_by_2-no_of_integral_points_on_edges+2)/2;

}

int main(){
	int x1,y1;
	cin>>x1>>y1;
	int x2,y2;
	cin>>x2>>y2;
	int x3,y3;
	cin>>x3>>y3;
	cout<<count(x1,y1,x2,y2,x3,y3)<<endl;
	return 0;
}