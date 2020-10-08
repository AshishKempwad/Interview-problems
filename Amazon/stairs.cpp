#include <bits/stdc++.h>
using namespace std;




int main(){
	int t;
	cin>>t;

	
		
	while(t--){
		int n;
		cin>>n;
		int * arr =new int[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int * dp=new int[n+1];
		dp[0]=0;
		dp[1]=1;

		for(int i=2;i<=n;i++){
			dp[i]=dp[i-1]+1;
			for(int j=i-1;j>=0;j--){
				
				if(j+arr[j]>=i)
					dp[i]=min(dp[i],dp[j]+1);
			}
		}
		
		
		
		int q;
		cin>>q;
		while(q--){
			int no;
			cin>>no;
			cout<<dp[no]<<endl;
		}


		delete [] dp;
		delete [] arr;
	}
	


	return 0;
}
