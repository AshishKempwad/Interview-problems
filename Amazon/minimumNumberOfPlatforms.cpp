/*
Given arrival and departure times of all trains that reach a railway station, 
the task is to find the minimum number of platforms required for the railway station so 
that no train waits.
We are given two arrays which represent arrival and departure times of trains that stop
*/


// Approach: The idea is to consider all events in sorted order.
 // Once the events are in sorted order, trace the number of trains at any time 
// keeping track of trains that have arrived, but not departed.


#include <bits/stdc++.h>
using namespace std;

int minPlatforms(int * arr,int * dep,int n){
	sort(arr,arr+n);
	sort(dep,dep+n);

	int i=1;
	int j=0;
	int max_platforms=1;
	int needed_platforms=1;
	while(i<n && j<n){
		if(arr[i]<=dep[j]){
			max_platforms++;
			i++;
		
		}
		else
		{
			max_platforms--;
			j++;
		}
		if(max_platforms>needed_platforms)
			needed_platforms=max_platforms;
	}
	return needed_platforms;
}


int main(){
	int n;
	cin>>n;
	int arr[n];
	int dep[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++)
		cin>>dep[i];
	cout<<minPlatforms(arr,dep,n)<<endl;
	return 0;
}