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

int n, q, s, x;
int start[N], endd[N], a[N];
ll BIT[N];
int timer;
vi adj[N];

void add(int pos, int val) {
	for (int i = pos; i <= n; i += (i & (-i)) ) {
		BIT[i] += val;
	}
}

ll sum(int pos) {
	ll res = 0;
	for (int i = pos; i >= 1; i -= (i & (-i)) ) {
		res += BIT[i];
	}
	return res;
}


void DFS(int u, int p) {
	start[u] = ++timer;
	add(timer, a[u]);

	for (int v : adj[u]) {
		if (v != p) {
			DFS(v, u);
		}
	}
	endd[u] = timer;
}


signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	FOR(i,1,n) cin >> a[i];
	
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	DFS(1, 0);

	while (q--){
		int type; cin >> type;

		if (type == 1) {
			cin >> s >> x;
			add(start[s], -a[s]);

			a[s] = x;
			add(start[s], +a[s]);
		}

		else {
			cin >> s;
			cout << sum(endd[s]) - sum(start[s] - 1) << "\n";
		}
	}
	return 0;
}
