#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> freq(26, 0);
vector<vector<int>> grid;

int main(){
    string s; cin >> s;

    for(char x : s){
        freq[x - 'A']++;
    }

    string sodd = "";
    string front = "";
    ll odds = 0;
    for(int x = 0; x < 26; x++){

        if(freq[x]&1){
            odds++;
            while(freq[x] != 0){
                sodd += x + 'A';
                freq[x]--;
            }
            if(odds > 1){
                cout << "NO SOLUTION";
                return 0;
            }
        } else{
            for(int i = 0; i < freq[x]/2; i++){
                front += x + 'A';
            }
        }
    }

    string final = front + sodd;
    reverse(front.begin(), front.end());
    final += front;

    cout << final;
    return 0;
}