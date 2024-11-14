// https://codeforces.com/contest/1999/problem/A

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tleslayer ios::sync_with_stdio(0); cin.tie(NULL);

int eval(int a, int b){
    if(a > b) return 1;
    if(a == b) return 0;
    if(a < b) return -1;
}


int main(){
    tleslayer;

    int cases; cin >> cases;
    while(cases--){
        int a, b, c, d; cin >> a >> b >> c >> d;
        int ans = 0;

        ans += ( eval(a, c) + eval(b,d) ) > 0;
        ans += (eval(a, d) + eval(b,c)) > 0;
        ans += (eval(b, c) + eval(a,d)) > 0;
        ans += (eval(b, d) + eval(a,c)) > 0;

        cout << ans;
        if(cases) cout << "\n";


    }
    return 0;
}
