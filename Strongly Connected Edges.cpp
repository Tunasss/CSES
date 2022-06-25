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

vector<ii> ans;
bool flag = 0; 
ll cnt = 0;
vll adj[SIZE];
ll vis[SIZE], low[SIZE];

void dfs(ll u, ll p) {

    vis[u] = cnt++;
    low[u] = vis[u];

    for (auto v : adj[u]) {
        if (v != p) {
            if (vis[v]) {
                low[u] = min(low[u], vis[v]);
                if (vis[v] > vis[u])
                    ans.pb({v, u});
            }
            else {
                dfs(v, u);
                ans.pb({u, v});
                low[u] = min(low[v], low[u]);
                if (low[v] > vis[u]) 
                    flag = true;
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

	ll n, m; 
	cin >> n >> m;
    FOR(i,1,m) {
        ll x, y; 
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, 0);

    if (flag){
    	cout << "IMPOSSIBLE";
    	return 0;
    } 

    FOR(i,1,n){
        if (!vis[i]){
	    	cout << "IMPOSSIBLE";
	    	return 0;
    	} 
    }
    for (ii res : ans)
        cout << res.st << ' ' << res.nd << '\n';
    
    return 0;
}
