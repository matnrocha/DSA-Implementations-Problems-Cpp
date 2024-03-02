#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxNum = 2e5 + 7;
#define tleslayer ios::sync_with_stdio(0); cin.tie(NULL)


ll N;
vector<ll> v(maxNum);

void update(ll idx, ll val) {
    for (int i = idx; i <= N; i += i & -i) {
        v[i] += val;
    }
}

ll query(ll idx) {
    ll sum = 0;
    for (int i = idx; i > 0; i -= i & -i) {
        sum += v[i];
    }
    return sum;
}

int main() {
    tleslayer;

    ll Q, x;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> x;
        update(i, x);
        update(i + 1, -x);
    }
    for (int q = 0; q < Q; q++) {
        ll t;
        cin >> t;

        if (t == 1) {
            ll a, b;
            cin >> a >> b >> x;
            update(b + 1, -x);
            update(a, x);
        } else if (t == 2) {
            ll k;
            cin >> k;
            cout << query(k) << "\n";
        }
    }

    return 0;
}
