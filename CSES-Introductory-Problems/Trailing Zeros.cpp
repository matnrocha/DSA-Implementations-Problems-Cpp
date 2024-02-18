#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v;
vector<vector<int>> grid;

int main(){
    ll n; cin >> n;
    ll aux = 1;

    ll cnt = 0;
    for(int i = 5; i <= n ; i+=5){
        ll j = i;
        while(j%5 == 0){
            cnt++;
            j /= 5;
        }
    }

    cout << cnt;
    return 0;
}