#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n; cin >> n;
    vector<int>v(n);

    ll a; cin >> a;
    ll sum = 0;
    for(int i = 0; i < n-1; i++){
        ll b; cin >> b;
        if(b < a){
            sum += a - b;
        } else{
            a = b;
        }
    }

    cout << sum;
    return 0;
}