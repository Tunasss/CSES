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
vll a[N];
bool vis[N];
ll ans = 0;

void dfs(ll u, ll p) {
	for (int v : a[u]) {
		if (v != p) {
			dfs(v, u);
			if (!vis[v] && !vis[u]){
				vis[v] = vis[u] = 1; 
				ans++;
			}
		}
	}
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n;
	FOR(i,1,n - 1) {
		ll u,v; 
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	dfs(1,-1);
	cout << ans;
    
    return 0;
}
