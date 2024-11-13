// https://codeforces.com/contest/2009/problem/C

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tleslayer ios::sync_with_stdio(0); cin.tie(NULL);

int main(){
    tleslayer;

    int cases; cin >> cases;
    while(cases--){
        int x, y, d; cin >> x >> y >> d;

        int minSteps_x, minSteps_y;
        minSteps_x = (x + d-1)/d;
        minSteps_y = (y + d-1)/d;


        int extra = 0;
        if(minSteps_x > minSteps_y) {
            extra = (minSteps_x - minSteps_y) -1;
        } else if(minSteps_y > minSteps_x){
            extra = (minSteps_y - minSteps_x);
        }

        int count = minSteps_x + minSteps_y + extra;

        cout << count << "\n";
    }
    return 0;
}
