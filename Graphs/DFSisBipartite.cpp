#include <bits/stdc++.h>
using namespace std;
vector<int> color;
vector<vector<int>> adj;

bool isBi(int v, int col){
    color[v] == col;

    for(auto to : adj[v]){
        if(color[to] == -1){
            if(!isBi(to, !col)){
                return false;
            }
        } else if(color[to] == color[v]){
            return false;
        }
    }
    return true;
}




int main(){
    int nv, na; cin >> nv >> na;

    color.resize(nv);
    adj.resize(nv);

    for(int i = 0; i < na; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool isBi = true;
    for(int i = 0; i < nv; i++){
        if(color[i] == -1){
            if(!isBi(0, 0)){
                isBi = false;
            }
        }
    }

    cout << isBi;


    return 0;
}
