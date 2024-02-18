#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


// to compute a ^ b
ll binpow(ll a, ll b){
    ll ans = 1;
    while(b > 0){
        if(b&1){
            ans *= a;
        }
        a *= a;
        b /= 2;
    }
    return ans;
}

// to compute (a^b) mod m
ll binpow(ll a, ll b, ll m){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b&1){
            ans = (ans * a) % m;
        }
        a = (a*a) % m;
        b /= 2;
    }

    return ans;
}

int main(){

    return 0;
}