#include <bits/stdc++.h>
using namespace std;

//APLICAÇÃO COM BFS

int main(){
    int nv, na;
    cin >> nv >> na;

    vector<vector<int>> adj;
    vector<int> dep(nv, 0);     // lista de dependências

    for(int i = 0; i < na; i++){
        int a, b;
        cin >> a >> b;          // A depende de B
        adj[b].push_back(a);    // na vida real, seria prov adj[a].push_back(b); e dep[b]++;
        dep[a]++;               // A depende de +1
    }

    vector<int> ordem;      //itens escolhidos      // se no final, ordem.size() != nv, deu ruim... ou é dependencia circular ou algo assim
    queue<int> q;           //itens aptos a serem escolhidos    // se houver prioridade de escolha, usar um priority queue

    for(int i = 0; i < nv; i++) if(dep[i] == 0) q.push(i);  // pega todos com dep == 0

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        ordem.push_back(curr);

        for(int to : adj[curr]){
            dep[to]--;                          //um pre-requisito cumprido
            if(dep[to] == 0) q.push(to);     //se possivel, colocar na queue
        }
    }

    if(ordem.size() != nv){
        cout << "Tem um ciclo aqui!";
    } else{
        for(auto x : ordem){
            cout << x << " ";
        }
    }

    return 0;
}
