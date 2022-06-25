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
ll dist[2][N];
vll adj[N];

ll dfs(ll u, ll p, ll d, ll i) {
	dist[i][u] = d;
	ll opt = -1;
	for (ll v : adj[u]) {
		if (v != p) {
			ll x = dfs(v, u, d + 1, i);
			if (opt == -1 || dist[i][x] > dist[i][opt]) opt = x;
		}
	}
	return opt == -1 ? u : opt;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll n; 
	cin >> n;
	FOR(i,1,n-1){
		ll u, v; 
		cin >> u >> v; 

		adj[u].pb(v); 
		adj[v].pb(u);
	}
	ll mxNode = dfs(1, 1, 0, 0);

	ll mxNode2 = dfs(mxNode, mxNode, 0, 0);

	dfs(mxNode2, mxNode2, 0, 1);

	FOR(i,1,n){
		cout << max(dist[0][i], dist[1][i]) << " ";
	}

    return 0;
}
