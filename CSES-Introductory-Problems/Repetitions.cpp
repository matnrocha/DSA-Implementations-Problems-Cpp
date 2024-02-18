#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s; cin >> s;
    ll max_len = 1;

    ll l = 0; ll r = 1;
    while(r <= s.size()-1){
        if(s[l] == s[r]){
            max_len = max(max_len, (r-l+1));
            r++;
        } else{
            l++;
        }
    }

    cout << max_len;
    return 0;
}