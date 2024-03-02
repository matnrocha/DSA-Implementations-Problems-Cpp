#include <bits/stdc++.h>
using namespace std;

int Knapsack(int W, int wt[], int val[], int i, vector<vector<int>>& F){

    if (i < 0)
        return 0;
    if (F[i][W] != -1)
        return F[i][W];

    if (wt[i] > W) {
        F[i][W] = Knapsack(W, wt, val, i - 1, F);
        return F[i][W];
    } else {
        F[i][W] = max(val[i] + Knapsack(W - wt[i], wt, val, i - 1, F), Knapsack(W, wt, val, i - 1, F));
        return F[i][W];
    }
}

int main(){
    int W, itens; cin >> W >> itens;
    int valA[itens];
    int pesos[itens];
    memset(pesos, 0, itens);
    memset(valA, 0, itens);
    for(int i = 0; i < itens; i++){
        int wt; int val; cin >> wt >> val;
        valA[i] = val;
        pesos[i] = wt;
    }
    vector<vector<int>> dp(itens, vector<int>(W+1,-1));
    cout << Knapsack(W, pesos, valA, itens - 1, dp);

    return 0;
}