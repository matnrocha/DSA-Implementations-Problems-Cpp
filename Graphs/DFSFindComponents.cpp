#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<ll>> adj;
vector<bool> vis;
vector<ll> comp;

ll nv;

void dfs(ll s){
    if(vis[s]) return;

    vis[s] = true;
    comp.push_back(s);

    for(int i = 0; i < adj[s].size(); i++){
        ll curr = adj[s][i];
        dfs(curr);
    }
}

void findComp(){
    fill(vis.begin(), vis.end(), 0);

    for(int i = 0; i < nv; i++){
        if(!vis[i]){
            comp.clear();
            dfs(i);

            for(ll u : comp){
                //cout << u << " ";
            }
        }
    }
}


int main(){

    return 0;
}