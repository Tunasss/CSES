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
#define FOR(i,x,y) for(ll i = x; i <= y; ++i)
#define FOS(i,x,y) for(ll i = x; i >= y; --i)
#define EACH(i,x) for (auto &(i) : (x))
#define el cout << '\n';
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll N = 2e5 + 5;
ll n, a[N], num[N], ans;
map<ll,ll> f[N];
vll p[N], adj[N];

void sieve(){
	for(ll i = 2; i <= 2e5; ++i){
		if (num[i] == 0){
			for (ll j = i; j <= 2e5; j += i){
				num[j] = i;
			}
		}
	}
}

void dfs(ll u, ll t){
    ll temp = a[u];

    while(temp > 1){
        ll prime = num[temp];
 
        p[u].pb(prime);
        while(temp % prime == 0){
            temp /= prime;
        }
 
        f[u][prime] = 1;
    	ans = max(ans,1LL);
    }

    for(ll v : adj[u]){
        if(v == t) continue;
        dfs(v, u);
 
        for(ll x : p[u]){
            ans = max(ans, max(f[v][x] + f[u][x], f[v][x] + 1));
            f[u][x] = max(f[u][x], f[v][x] + 1);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);	
	cin >> n;

	sieve();

	FOR(i,1,n) cin >> a[i];

	FOR(i,2,n) {
		ll u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1,0);
	cout << ans;
	el;
    return 0;
}

