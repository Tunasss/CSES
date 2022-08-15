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
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

#define int long long

const ll N = 2e5 + 5;

int n,k;
vll adj[N];
ll s[N];

void dfs (int u, int p){
	s[u] = 1;
	for (int v : adj[u]){
		if (v == p) continue;
		dfs(v,u);
		s[u] += s[v];
	}
}

int get_cen(int u, int p){
	for(int v : adj[u]){
		if (v == p) continue;
		if (s[v] * 2 > n) return get_cen(v,u);
	}
	return u;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n;

    FOR(i,2,n){
    	int u, v;
    	cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
    }

    dfs(1,0);

    int cen = get_cen(1, 0);

    cout << cen; el;
    
    return 0;
}
