#include <bits/stdc++.h>
using namespace std;


int find_no_of_stairs(int n){
	
	int * arr=new int[n+1];
	arr[0]=0;
	arr[1]=1;
	arr[2]=2;
	for(int i=3;i<=n;i++){
		if(i%2 !=0)
			arr[i]=1+arr[i-2];
		else
			arr[i]=1+arr[i-1];
	}
	return arr[n];

}



int  main(){

	int n;
	cin>>n;
	cout<<find_no_of_stairs(n)<<endl;
	return 0;
}