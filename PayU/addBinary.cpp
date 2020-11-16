#include <bits/stdc++.h>
using namespace std;


int reverse(int n){
	int rev=0;
	while(n){
		rev=rev*10+(n%10);
		n=n/10;
	}
	return rev;

}


int main(){
	int n,m;
	cin>>n>>m;
	vector <int> res1;
	vector <int> res2;
	while(n){
		res1.push_back(n%2);
		n/=2;
	}
	while(m){
		res2.push_back(m%2);
		m/=2;
	}
	int carry=0;
	int i=0;
	int no=0;
	for(;i<res1.size()&&i<res2.size();i++){
		int sum=res1[i]+res2[i]+carry;
		carry=sum/10;
		sum=sum%10;
		no=no*10+sum;
	}
	while(i<res1.size()){
		int sum=res1[i]+carry;
		carry=sum/10;
		sum=sum%10;
		no=no*10+sum;

	}
	while(i<res2.size()){
		int sum=res2[i]+carry;
		carry=sum/10;
		sum=sum%10;
		no=no*10+sum;

	}
	if(carry==1)
		no=no*10+1;
	cout<<reverse(no)<<endl;

	return 0;
}