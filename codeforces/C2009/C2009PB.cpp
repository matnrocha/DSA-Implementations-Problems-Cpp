//https://codeforces.com/contest/2009/problem/B

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tleslayer ios::sync_with_stdio(0); cin.tie(NULL);

int main(){
    tleslayer;

    int cases; cin >> cases;
    while(cases--){
        int num; cin >> num;
        stack<int> dq;

        for(int i = 0; i < num; i++){
            for(int j = 0; j < 4; j++){
                char c; cin >> c;
                if(c == '#') dq.push(j+1);
            }
        }

        while(!dq.empty()) {
            cout << dq.top() << " ";
            dq.pop();
        }

        cout << "\n";
    }
    return 0;
}

