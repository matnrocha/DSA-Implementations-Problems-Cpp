#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll nv;
vector<vector<ll>> adj;
vector<bool> vis;

void dfs1(ll s){
    if(vis[s]) return;
    vis[s] = true;

    for(auto x : adj[s]){
        dfs1(x);
    }
}


void dfs2(ll s){
    vis[s] = true;

    for(auto x : adj[s]){
        if(!vis[x]){
            dfs2(x);
        }
    }
}


void dfs3(ll s){
    stack<ll> st;
    st.push(s);

    while(!st.empty()){
        ll curr = st.top();
        st.pop();

        if(!vis[curr]){
            vis[curr] = true;
            //add a um componente
            for(auto x : adj[curr]){
                st.push(x);
            }

            // se quiser numa ordem especifica (upwards or backwars)
            for(int i = adj[curr].size(); i >= 0; i--){
                st.push(adj[curr][i]);
            }
        }
    }
}



int main(){

    return 0;
}