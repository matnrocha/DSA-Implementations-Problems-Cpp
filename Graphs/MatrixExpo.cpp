/*
Problem Name: Graph Paths I
Problem Link: https://cses.fi/problemset/task/1723
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

template<typename... T>
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << "=" << a << ", "; err(++it, args...);}

#define int long long
#define pb push_back
#define F first
#define S second
#define vi vector<int>
#define vvi vector<vi>
const int inf = 1LL<<62;
const int md = 1000000007;

vvi mul(vvi a, vvi b) {
    vvi c(a.size(), vi(b[0].size()));
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b[0].size(); j++)
            for ( int k = 0; k < a[0].size(); k++)
                (c[i][j] += a[i][k]*b[k][j]%md)%=md;
    return c;
}


vvi exp( vvi x, int y) {
    vvi r(x.size(), vi(x.size()));
    for ( int i = 0; i < x.size(); i++) r[i][i] = 1;
    while (y>0){
        if (y&1) {
            r = mul(r,x);
        }
        y=y>>1;
        x = mul(x,x);
    }
    return r;
}
void solve(){
    //considering multiple edges
    int n,m, k; cin>>n>>m>>k;
    vvi adj(n,vi(n));
    for (int i = 0; i< m; i++) {
        int x,y; cin>>x>>y;
        x--; y--;
        adj[x][y]++;
    }
    adj = exp(adj,k);
    cout<<adj[0][n-1];
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    //cin>>t;
    for (int i = 1; i <= t; i++) {
        solve();
        cout<<'\n';
    }
}