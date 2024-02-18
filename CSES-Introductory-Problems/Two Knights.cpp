#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v;
vector<vector<int>> grid;

int main(){
    ll n; cin >> n;

    for(ll i = 1; i <= n; i++){
        ll poss = ((i*i)*(i*i - 1))/2;
        poss -= 4*(i-1)*(i-2);
        cout << poss << "\n";
    }

    return 0;
}