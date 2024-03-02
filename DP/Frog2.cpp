#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, range;
    cin >> n >> range;

    vector<int> weights(n); //dp
    vector<int> minCosts(n, INT_MAX);

    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }

    minCosts[0] = 0;

    for (int currS = 1; currS < n; currS++) {
        for (int jump = 1; jump <= range; jump++) {
            if (currS - jump >= 0) {        // x <1, 2, (3), 4, ...>
                int prevS = currS - jump;
                int jumpC = abs(weights[currS] - weights[prevS]);
                int totalC = jumpC + minCosts[prevS];
                minCosts[currS] = min(minCosts[currS], totalC);
            }
        }
    }

    cout << minCosts[n - 1] << endl;

    return 0;
}
