#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = 1e9+5;

vector<vector<pii>> g;

vector<int> dijkstra(int s, int n){
    vector<int> dist(n, INF);

    priority_queue<pii, vector<pii>, greater<pii>> pq; //dist, node

    dist[s] = 0;
    pq.emplace(0, s);

    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for(auto edge : g[u]){
            int v = edge.second;
            int w = edge.first;

            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist;
}

int main(){
    int nv; cin >> nv;
    g.resize(nv);
    return 0;
}