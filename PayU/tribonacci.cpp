#include <bits/stdc++.h>
using namespace std;


  
void printTrib(int n) 
{ 
    if (n < 1) 
        return; 
  
    
    int first = 0, second = 0; 
    int third = 1; 
  
    cout << first << " "; 
    if (n > 1) 
        cout << second << " "; 
      
    if (n > 2) 
        cout << third << " "; 
  
   
    for (int i = 3; i < n; i++)  
    { 
        int curr = first + second + third; 
        first = second; 
        second = third; 
        third = curr; 
  
        cout << curr << " "; 
    } 
} 

int main(){
	int k;
	cin>>k;
	printTrib(k);
	cout<<endl;

	return 0;
 }
