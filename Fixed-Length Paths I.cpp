#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int ans = 0;
vector <int> g[N];
int sz[N];
int used[N];
vector <int> vec;
 
void count_sz(int v, int pr) {
    sz[v] = 1;
    for (auto to : g[v]) {
        if (to == pr || used[to]) continue;
        count_sz(to, v);
        sz[v] += sz[to];
    }
}
 
int find_centoid(int v, int pr, int k) {
    for (auto to : g[v]) {
        if (to == pr || used[to]) continue;
        if (sz[to] > k / 2) {
            return find_centoid(to, v, k);
        }
    }
    return v;
}
 
void find_ans(int v, int pr, int h) {
    vec.pb(h);
    for (auto to : g[v]) {
        if (!used[to] && to != pr) {
            find_ans(to, v, h + 1);
        }
    }
}
 
void decomposition(int v, int cmp_sz, int k) {
    count_sz(v, 0);
    int centroid = find_centoid(v, 0, cmp_sz);
    used[centroid] = true;
    vector <int> d(cmp_sz + 1);
    d[0] = 1;
    for (auto to : g[centroid]) {
        if (!used[to]) {
            vec.clear();
            find_ans(to, centroid, 1);
            for (auto it : vec) {
                if (k - it >= 0 && k - it <= cmp_sz) {
                    ans += d[k - it];
                }
            }
            for (auto it : vec) {
                d[it] y++;
            }
        }
    }
    count_sz(centroid, 0);
    for (auto to : g[centroid]) {
        if (!used[to]) decomposition(to, sz[to], k);
    }
}
 
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    decomposition(1, n, k);
    cout << ans;
}
 

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll t = 1;
    if (true) cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}