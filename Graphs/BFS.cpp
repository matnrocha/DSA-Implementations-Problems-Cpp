#include <bits/stdc++.h>
using namespace std;

int main(){
    int nv; cin >> nv;                      //numero de vertices
    int sv; cin >> sv;                      //vertice source
    vector<vector<int>> adj(nv);        //lista de adjacencia

    vector<bool> vis(nv, false);                       //visitado
    vector<int> p(nv);                   // pais - path
    vector<int> d(nv);                   // distancias do source pra o vertice


    queue<int> q;

    // BFS //
    q.push(sv);
    vis[sv] = true;
    p[sv] = -1;
    d[sv] = 0;

    while(!q.empty()){
        int v = q.front();                  // tira o primeiro da fila
        q.pop();

        for(int to : adj[v]){                // pra cada vizinho
            if(!vis[to]){                            // se não for visitado
                vis[to] = true;                              // visita, joga na fila, seta dist, seta pai
                q.push(to);
                d[to] = d[v]+1;
                p[to] = v;
            }
        }
    }

    // RECUPERAR PATH DE U //
    int u; cin >> u;
    if(!vis[u]){                                            //Se não for visitado, é componente desconexo
        //no path
    } else{
        vector<int> path;                                    //vetor path
        for(int v = u; v!= -1; v = p[v]){                   //roda até achar o primeiro (p[v] = -1)
            path.push_back(v);
        }

        reverse(path.begin(), path.end());          // reverse pra ir na direcao primeiropai->ultimofilho

        for(int v : path){
            //cout << v << " ";
        }
    }

    return 0;
}



