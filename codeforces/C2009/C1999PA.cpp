// https://codeforces.com/contest/1999/problem/A

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tleslayer ios::sync_with_stdio(0); cin.tie(NULL);

int main(){
    tleslayer;

    int cases; cin >> cases;
    while(cases--){
        int a; cin >> a;

        cout << a/10 + a%10 << "\n";
    }
    return 0;
}
