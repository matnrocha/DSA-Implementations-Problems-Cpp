#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        size.resize(n+1);
        parent.resize(n+1);

        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int v){
        if(v == parent[v]){
            return v;
        }
        return parent[v] = findPar(parent[v]);      //path compression
    }

    //UNIONS

    void unionRank(int u, int v){
        int upu = findPar(u);
        int upv = findPar(v);

        if(upu == upv) return;

        if(rank[upu] > rank[upv]){
            parent[upv] = upu;
        } else if(rank[upv] > rank[upu]){
            parent[upu] = upv;
        } else{
            parent[upv] = upu;
            rank[upu]++;
        }
    }


    void unionSize(int u, int v){
        int upu = findPar(u);
        int upv = findPar(v);

        if(upu == upv) return;

        if(size[upv] > size[upu]){
            parent[upu] = upv;
            size[upv] += size[upu];
        } else{
            parent[upv] = upu;
            size[upu] += size[upv];
        }
    }

};

int main(){
    int nv, na; cin >> nv >> na;

    vector<pair<int, pair<int, int>>> edges;    // {wt, {from, to}}

    for(int i = 0; i < na; i++){
        int wt, v, u;
        cin >> wt >> v >> u;
        edges.push_back({wt, {v, u}});
    }

    DisjointSet ds(nv);

    sort(edges.begin(), edges.end());
    int mstWt;

    for(auto x : edges){
        int wt = x.first;
        int v = x.second.first;
        int u = x.second.second;

        if(ds.findPar(v) != ds.findPar(u)){
            mstWt += wt;
            ds.unionSize(u, v);
        }
    }

    cout << mstWt;


    return 0;
}