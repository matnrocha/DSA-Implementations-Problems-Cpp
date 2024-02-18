#include <bits/stdc++.h>
using namespace std;

bool isBipartite(int nv, vector<vector<int>>& adj, vector<int>& color){
    queue<int> q;

    q.push(0);
    color[0] = 0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto to : adj[curr]){
            if(color[to] == -1){            // if not colored, attach the oposite color
                color[to] = !color[curr];
                q.push(to);
            } else if(color[to] == color[curr]){
                return false;
            }
        }
    }
    return true;

}

int main(){
    int nv, na; cin >> nv >> na;

    vector<vector<int>> adj(nv);
    vector<int> color(nv);
    fill(color.begin(), color.end(), -1);

    for(int i = 0; i < na; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool isBi = true;
    for(int i = 0; i < nv; i++){
        if(color[i] == -1){
            if(!isBipartite(nv, adj, color)){
                isBi = false;
            }
        }
    }

    cout << isBi;




    return 0;
}