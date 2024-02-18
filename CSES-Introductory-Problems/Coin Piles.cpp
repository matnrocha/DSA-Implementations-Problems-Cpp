#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v;
vector<vector<int>> grid;

int main(){
    ll t; cin >> t;
    while(t--){
        ll a, b; cin >> a >> b;
        if((a+b)%3 == 0){
            if(max(a,b) > 2* min(a, b)){
                cout << "NO\n";
                continue;
            } else{
                cout << "YES\n";
            }
        } else{
            cout << "NO\n";
        }
    }
    return 0;
}