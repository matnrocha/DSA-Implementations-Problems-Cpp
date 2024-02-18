#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll sum = 0;
    ll n; cin >> n;

    for(int i = 0; i < n-1; i++){
        ll a; cin >> a;
        sum += a;
    }

    ll max_sum = ((1 + n) * n)/2;

    cout << max_sum - sum;
    return 0;
}