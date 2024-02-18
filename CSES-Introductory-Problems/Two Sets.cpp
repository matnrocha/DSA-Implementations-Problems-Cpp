#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v1;
vector<int> v2;
vector<vector<int>> grid;

int main(){
    ll n; cin >> n;

    if(n%2){
        ll l = 1; ll r = n-1;
        v2.push_back(n);

        ll cnt = 1;
        while(l < r){
            if(l&1){
                v1.push_back(l);
                v1.push_back(r);
            } else{
                v2.push_back(l);
                v2.push_back(r);
            }
            l++; r--;
            cnt++;
        }

        if(v1.size() - v2.size() == 1 and cnt%2 == 0){
            cout << "YES\n";
            cout << v1.size() << "\n";
            for(auto x : v1){
                cout << x << " ";
            }

            cout << "\n";
            cout << v2.size() << "\n";
            for(auto x : v2){
                cout << x << " ";
            }
        } else{
            cout << "NO";
        }
    } else{
        if(n%4 == 0){
            ll l = 1; ll r = n;

            ll cnt = 0;
            while(l < r){
                if(l&1){
                    v1.push_back(l);
                    v1.push_back(r);
                } else{
                    v2.push_back(l);
                    v2.push_back(r);
                }
                cnt++;
                l++; r--;
            }

            if(v1.size() - v2.size() == 0){
                cout << "YES\n";
                cout << v1.size() << "\n";
                for(auto x : v1){
                    cout << x << " ";
                }

                cout << "\n";
                cout << v2.size() << "\n";
                for(auto x : v2){
                    cout << x << " ";
                }
            } else{
                cout << "NO";
            }

        } else{
            cout << "NO";
        }
    }

    return 0;
}