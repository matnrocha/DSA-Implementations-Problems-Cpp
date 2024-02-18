#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v;
vector<vector<int>> grid;

int main(){
    ll n; cin >> n;
    if(n == 1 or n >= 4){
        for(int i = 2; i <= n; i+=2){
            cout << i << " ";
        }
        for(int i = 1; i <= n; i+=2){
            cout << i << " ";
        }
    } else{
        cout << "NO SOLUTION";
    }
    return 0;
}