#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+5;

int main(){
    int nv, na, origem;
    cin >> nv >> na >> origem;

    queue<int> q;
    vector<vector<int>> adj(nv);
    vector<int> dist(nv, INF);


    q.push(origem);
    dist[origem] = 0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        //previsit
        for(int to : adj[curr]){
            if(dist[to] > dist[curr] + 1){
                dist[to] = dist[curr] + 1;
                q.push(to);
            }
        }
        //posVisit
    }


    return 0;
}
