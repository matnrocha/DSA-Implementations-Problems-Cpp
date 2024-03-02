#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tleslayer ios::sync_with_stdio(0); cin.tie(NULL)


const ll N = 2e5 + 7;
ll n;
vector<ll> a(N);
vector<ll> segtree(4*N);

void build(ll i, ll l, ll r){

    if(l == r){
        segtree[i] = a[l];
        return;
    }

    ll mid = l + ((r-l)/2);
    build(2*i, l, mid);
    build(2*i + 1, mid + 1, r);

    segtree[i] = segtree[2*i] + segtree[2*i +1];
}

void update(ll i, ll l, ll r, ll k, ll u){
    if(l == r){
        segtree[i] = u;
        return;
    }

    ll mid = l + (r-l)/2;
    if(k <= mid){
        update(2*i, l, mid, k, u);
    } else{
        update(2*i+1, mid+1,  r, k, u);
    }

    segtree[i] = segtree[2*i] + segtree[2*i +1];
}

ll query(ll i, ll l, ll r, ll a, ll b){
    if(b < l or a > r){
        return 0;
    }
    else if(a <= l and r <= b){
        return segtree[i];
    }

    ll mid = l + (r-l)/2;
    ll p = query(2*i, l, mid, a, b);
    ll q = query(2*i+1, mid+1,  r, a, b);

    return p + q;
}



int main() {
    tleslayer;

    ll q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);


    while(q--){
        int qt;
        cin >> qt;
        if(qt == 1){
            ll k, u;
            cin >> k >> u;

            update(1, 1, n, k, u);
        } else{
            ll a, b;
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << "\n";
        }
    }

}