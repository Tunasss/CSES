#include <bits/stdc++.h>
#include <unordered_map>
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
#define er equal_range
#define bin binary_search
#define vll vector<ll>
#define vi vector<int>
#define all(v) (v).begin(), (v).end()
#define FOR(i,x,y) for(ll i = x; i <= y; i++)
#define FOS(i,x,y) for(ll i = x; i >= y; i--)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll N = 2e5 + 5;
ll n;
vll adj[N];
ll dp[N], ans[N];

void dfs1(ll u, ll p, ll depth = 0) {
	ans[1] += depth;
	dp[u] = 1;
	for (ll v : adj[u]) if (v != p) {
		dfs1(v, u, depth + 1);
		dp[u] += dp[v];
	}
}

void dfs2(ll u, ll p) {
	for (ll v : adj[u]) if (v != p) {
		ans[v] = ans[u] + n - 2 * dp[v];
		dfs2(v, u);
	}
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n;
	FOR(i,1,n - 1){
		ll u,v; 
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs1(1,0,0);
	dfs2(1,0);
	FOR(i,1,n) cout << ans[i] << ' ';
    
    return 0;
}
