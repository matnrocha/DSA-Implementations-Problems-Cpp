#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v;
vector<vector<int>> grid;

int main(){
    ll t; cin >> t;
    while(t--){
        ll r, c; cin >> r >> c;
        ll row = max(r, c);
        ll z2 = row*row;

        ll ans;
        if(row&1){
            ans = z2 - r + 1 - (row - c);
        } else{
            ans = z2 - c + 1 - (row - r);
        }

        cout << ans << " ";
    }
    return 0;
}