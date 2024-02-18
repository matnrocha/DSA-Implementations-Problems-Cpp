#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll nv, na, sv;
vector<vector<ll>> adj;
vector<int> p;
vector<bool> vis;

bool hasCycle = false;

bool dfsCycle(int sv){
    vis[sv] = true;

    for(auto to : adj[sv]){
        if(!vis[to]){
            if(dfsCycle(to)){           // propaga o true
                return true;
            }
        }
        else if(p[sv] != to){               // se já for visitado e não for o pai, tem ciclo
            return true;
        }
    }
}

int main(){
    cin >> nv >> na >> sv;

    adj.resize(nv);
    p.resize(nv);

    for(int i = 0; i < na; i++){
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    p[sv] = -1;
    fill(vis.begin(), vis.end(), false);
    for(int i = 0; i < nv; i++){                            //for connected components(start w 0 or sv)
        if(!vis[i]){
            if(dfsCycle(i)){
                hasCycle = true;
            }
        }
    }

    return 0;
}