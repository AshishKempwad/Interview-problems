#include<iostream>
#include<vector>
using namespace std;



// Given a string, what is the minimum number of adjacent swaps required to convert a string into a palindrome. If not possible, return -1.

// Practice online: https://www.codechef.com/problems/ENCD12

int main() {
    int T; cin >> T;
    string s;
    
    for(; T > 0 ; T--){
        cin >> s;
        vector<int> cc(26,0);
        
        for(char c : s)
            cc[c-'a']++;
         
        int occured = 0;
        for(int i = 0 ; i < 26 ; i++)
            occured += (cc[i] & 1);
        
        // more than one element occured odd no. of times
        if(occured > 1){
            cout << -1 << endl;
            continue;
        }
        
        // core begins
        int end = s.length()-1, ans = 0;
        for(int i = 0 ; i < s.length()/2 ; i++){
            if(s[i]==s[end-i])
                continue;
            
            // proceed if ends are not same
            int j, k;
            for(j = i+1 ; j <= end-i && s[j]!=s[end-i] ; j++);
            for(k = end-i-1; k >= i && s[k]!=s[i] ; k--);
            
            // choose minimum distance
            ans += min(j-i, end-i-k);
            if( j-i < end-i-k){                    
                for(int p = j; p > i ; p--)
                    swap(s[p], s[p-1]);
            }else{
                for(int p = k ; p < end-i ; p++)
                    swap(s[p], s[p+1]);
            }            
        }
        
        // core end   
        cout << ans << endl;
    }
}