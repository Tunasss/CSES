#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define FOR(i,x,y) for(int i = x; i <= y; ++i)
#define pb push_back
const int MOD = 1e9 + 7;

int n, m;
vi adj[21];
int f[(1 << 20)][20];
 
int dp(int mask, int u){
	if (mask == 0 && u == (n - 1)) return 1;
	if (mask == 0 || u == (n - 1)) return 0z 
	if (f[mask][u] != -1) return f[mask][u];
 
	int ans = 0;
 
	for (auto v : adj[u]){
		if (mask & (1 << v)){
			ans += dp(mask ^ (1 << v), v);
			ans %= MOD;
		}
	}
 
	return f[mask][u] = ans;
}
 
signed main()
{
	memset(f, -1, sizeof f);
	cin >> n >> m;
 
	FOR(i,1,m){
		int u,v;
		cin >> u >> v; u--, v--;
		adj[u].pb(v);
	}
 
	int masks = ((1 << n) - 1) ^ (1 << 0);
	cout << dp(masks, 0);

	return 0;
}