#include <bits/stdc++.h>
using namespace std;


int prec(char a){
	if(a == '^')
		return 3;
	if(a=='*' || a=='/')
		return 2;
	if(a=='+' || a=='-')
		return 1;
	else
		return -1;
}

string convertInfixToPrefix(string s){
	stack <char> st;
	string res;
	for(int i=0;i<s.length();i++){
		if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || s[i]==' ')
			res+=s[i];
		else if(s[i] == '(')
			st.push(s[i]);
		else if(s[i] == ')')
		{
			while(!st.empty() && st.top()!='('){

				res+=st.top();
				st.pop();
				
			}

			if(st.top() == '(')
				st.pop();

		}

		else{
			while(!st.empty() && prec(s[i])<=prec(st.top())){
				res+=st.top();
				st.pop();
				
			}
			st.push(s[i]);
		}

	}

	while(!st.empty()){
		res+=st.top();
		st.pop();
	}
	return res;
}


int main(){
	string s;
	cin>>s;

	string res=convertInfixToPrefix(s);
	cout<<res<<endl;

	return 0;
}