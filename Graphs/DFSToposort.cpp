#include <bits/stdc++.h>

// Presumindo que o grafo é aciclico, podemos rodar desse jeito.
// Se não, testar se tem ciclo usando dfs.

using namespace std;
typedef long long ll;
vector<vector<ll>> adj;
vector<bool> vis;
vector<ll> ans;

ll nv;

void dfs(ll s){
    vis[s] = true;

    for(auto x : adj[s]){
        if(!vis[x]){
            dfs(x);
        }
    }
    ans.push_back(s);
}

void toposort(){
    fill(vis.begin(), vis.end(), false);
    ans.clear();
    for(int i = 0; i < nv; i++){                            // dfs em todos os nós (caso compontes > 1)
        if(!vis[i]){
            dfs(i);
        }
    }

    reverse(ans.begin(), ans.end());

    // se quiser printar ans, é aqui
}


int main(){

    return 0;
}