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

/*
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }
*/

#define int long long

const ll N = 100001;
#define pii pair<long long,int>
const ll oo = LLONG_MAX;

vector<pii> adj[N];
ll dis[N];
ll ways[N];
int maxf[N], minf[N];
bool vis[N];

int n,m;

void Dijkstra(){
	FOR(i,1,n) dis[i] = oo;
	dis[1] = 0;
	ways[1] = 1;
	priority_queue<pair<int, int>> myque;

	myque.push({0,1});
	while(myque.size()){
		pii pu = myque.top();
		myque.pop();
		int u = pu.nd;
		ll wu = -pu.st;

		if (vis[u]) continue;
		vis[u] = 1;

		for (auto pv : adj[u]){
			int v = pv.st;
			ll wv = pv.nd;

			if (dis[v] == dis[u] + wv){
				ways[v] = (ways[v] + ways[u]) % MOD; 
				minf[v] = min(minf[v], minf[u] + 1);
				maxf[v] = max(maxf[v], maxf[u] + 1);
			}

			if (dis[v] > dis[u] + wv){
				dis[v] = dis[u] + wv;

				ways[v] = ways[u]; 
				minf[v] = minf[u] + 1;
				maxf[v] = maxf[u] + 1;

				myque.push({-dis[v],v});
			}
		}
	}
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        adj[v].push_back({u, w});
    }

    Dijkstra();

    cout << dis[n] << " " << ways[n] << " " << minf[n] << " " << maxf[n];
    
    return 0;
}