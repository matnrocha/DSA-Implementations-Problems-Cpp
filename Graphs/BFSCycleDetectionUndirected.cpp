#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> adj;
vector<bool> vis;
vector<ll> p;

// sc = O(3n)
// tc = O(n + 2e)

int main(){
    ll nv, na, sv; cin >> nv >> na >> sv;

    adj.resize(nv);
    p.resize(nv);

    for(int i = 0; i < na; i++){
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    vis.resize(nv, false);
    bool hasCycle = false;
    for(int i = 0; i < nv; i++){
        if(!vis[i]){

            q.push(i);
            vis[i] = true;
            p[i] = -1;

            while(!q.empty()){
                int curr = q.front();
                q.pop();

                for(auto to : adj[curr]){
                    if(!vis[to]){
                        vis[to] = true;
                        p[to] = curr;
                        q.push(to);
                    } else if(p[curr] != to){           // só isso muda do bfs normal
                        hasCycle = true;                //o resto é igual
                    }
                }
            }
        }
    }

    cout << hasCycle;


    return 0;
}