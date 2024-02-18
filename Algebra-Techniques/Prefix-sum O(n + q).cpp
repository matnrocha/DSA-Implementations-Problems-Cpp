#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, q; cin >> n >> q;
    vector<ll> v(n);        //0-based
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<ll> pref(n+1);       //1-based
    for(int i = 1; i < n+1; i++){
        pref[i] = pref[i-1] + v[i-1];
    }

    //pref[0] = 0;

    for(int i = 0; i < q; i++){
        int a,b; cin >> a >> b;
        cout << pref[b] - pref[a-1];            //soma entre os intervalos de a->b
    }

    return 0;
}