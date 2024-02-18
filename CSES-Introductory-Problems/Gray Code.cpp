#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v;
vector<vector<int>> grid;

int main(){
    ll n; cin >> n;

    for(int i = 0; i < (1 << n); i++){
        ll p = i ^ (i >> 1);
        bitset<32> foo(p);
        string a = foo.to_string();

        for(int i = 32 - n; i < 32; i++){
            cout << a[i];
        }

        cout << "\n";
    }
    return 0;
}