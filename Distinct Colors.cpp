#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int, int> ii;
#define file "TEST"
#define st first
#define nd second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define bin binary_search
#define vll vector<ll>
#define vi vector<int>
#define all(v) (v).begin(), (v).end()
#define FOR(i,x,y) for(ll i = x; i <= y; ++i)
#define FOS(i,x,y) for(ll i = x; i >= y; --i)
#define EACH(i,x) for (auto &(i) : (x))
#define el cout << '\n';
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;

/*
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }
*/

//#define int long long
const ll N = 2e5 + 5;

vi adj[N];
int ans[N];
set<int> colors[N];

void dfs(int u , int p ) {
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);

		if (colors[u].size() < colors[v].size()) {
			swap(colors[u], colors[v]);
		}
		for (int x : colors[v]) {
			colors[u].insert(x);
		}
	}
	ans[u] = colors[u].size();
}
signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;

	FOR(i, 1, n) {
		int a; cin >> a;
		colors[i].insert(a);
	}
	FOR(i, 2, n) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);

	FOR(i,1,n) cout << ans[i] << " ";

	return 0;
}
