#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v;
vector<vector<int>> grid;

int main(){
    ll n; cin >> n;
    cout << n << " ";

    while(n != 1){
        if(n&1){
            n = 3*n + 1;
        } else{
            n /= 2;
        }
        cout << n << " ";
    }
    return 0;
}