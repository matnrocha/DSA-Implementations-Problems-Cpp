#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v;
vector<vector<int>> grid;
ll mod = 1e9+7;

// BINARY EXPONENCIATION

int main(){
    ll n; cin >> n;

    ll a = 2;

    ll ans = 1;
    while(n > 0){
        a %= mod;
        if(n&1){
            ans = (ans * a) % mod;
        }
        a = (a*a)%mod;
        n /= 2;
    }

    cout << ans;
    return 0;
}