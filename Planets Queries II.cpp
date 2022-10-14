#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;
#define file "TEST"
#define st first
#define nd second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
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
const long long oo = 1e18;
const long long N = 2e5 + 5;
 
int n, q, t[N], in[N], color[N], up[18][N], h[N], End[N];
 
void dfs(int u, int x = -1) {
	color[u] = 1;
	int v = t[u];
	if (color[v] == 0) dfs(v, 0);
	if (color[v] == 1) {
		color[u] = 2;
		h[u] = 1;
		End[u] = u;
		return;
	}
	color[u] = 2;
 
	h[u] = h[v] + 1;
	End[u] = End[v];
}
 
int ANC(int k, int u) {
	for (int i = 17; i >= 0; i--)
		if (k & (1 << i)) 
			u = up[i][u];
	return u;
}
 
bool is_anc(int a, int b) { // a -> b
	int delta = h[a] - h[b];
	if (delta < 0) return false;
	return ANC(delta, a) == b;
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i ++) {
		cin >> t[i];
		in[t[i]] ++;
		up[0][i] = t[i];
	}
 
	for (int i = 1; i < 18; i ++)
		for (int j = 1; j <= n; j ++)
			up[i][j] = up[i - 1][up[i - 1][j]];
	for (int i = 1; i <= n; i ++) if (in[i] == 0) 
		dfs(i);
 
	for (int i = 1; i <= n; i ++) if (color[i] == 0)
		dfs(i);
 
	int a, b;
	while (q--) {
		cin >> a >> b;
 
		int ans = 0;
		if (!is_anc(a, b)) 
			ans += h[a] - h[End[a]] + (End[a] != t[End[a]]), a = t[End[a]];
		if (h[a] < h[b]) cout << -1 << '\n'; else {
			int delta = h[a] - h[b];
			cout << (ANC(delta, a) == b ? ans + delta : - 1) << '\n';
		}
	}
 
	return 0;
}
