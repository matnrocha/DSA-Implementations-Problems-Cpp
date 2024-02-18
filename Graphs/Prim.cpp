#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<vector<pii>> adj;

int prim(int n){        //retorna a soma
    priority_queue<pii, vector<pii>, greater<pii>> pq;          //min-heap (wt - node)
    vector<bool> vis(n, false);

    pq.push({0,0});
    int sum = 0;

    while(!pq.empty()){
        int wt = pq.top().first;
        int node = pq.top().second;

        if(!vis[node]){
            vis[node] = true;
            sum+= wt;
            for(auto to : adj[node]){
                int u = to.first;
                int w = to.second;

                if(!vis[u]){
                    pq.push({w, u});
                }
            }
        }
    }
    return sum;
}

