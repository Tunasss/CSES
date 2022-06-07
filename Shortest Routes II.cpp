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

const ll oo = 10000000000000;
const ll N = 505;
ll dis[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    memset(dis, 00, sizeof dis);

    ll n, m, q;
    cin >> n >> m >> q;

    FOR(i,1,n) FOR(j,1,n) dis[i][j] = oo;

    while(m--){
        ll u,v,w; 
        cin >> u >> v >> w;
        dis[u][u] = 0; 
        dis[v][v] = 0;
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[u][v], w);
    }

    FOR(k,1,n){
        FOR(i,1,n){
            FOR(j,1,n){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while(q--){
    	ll a, b;
    	cin >> a >> b;
    	if (dis[a][b] != oo) cout << dis[a][b] << '\n';
    	else cout << -1 << '\n';
    }
    
    return 0;
}
