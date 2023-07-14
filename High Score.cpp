#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second

#define int long long
#define pii pair<int,int>

int const oo = 1e17;
int const N = 5e5 + 5;

vector<pii> adj[N];
int dis[N];

int n, m;

void BFS() {
    for (int i = 1; i <= n; i++) dis[i] = oo;

    dis[1] = 0;
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= n; j++){
            for (auto x : adj[j]){
                if (dis[j] == oo) continue;
                dis[x.st] = min(dis[j] + x.nd, dis[x.st]);
            }
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= n; j++){
            for (auto x : adj[j]){
                if (dis[j] == oo) continue;
                if (dis[j] + x.nd < dis[x.st]){
                    dis[x.st] = -oo;
                }
            }
        }
    }
}

signed main() {
    cin >> n >> m;9
    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        adj[v].push_back({u, -w});
    }

    if (n == 1 && m == 1){
        cout << -1;
        return 0;
    }

    BFS();

    if (dis[n] == -oo) cout << -1;
    else cout << dis[n] * -1LL;

    return 0;
}