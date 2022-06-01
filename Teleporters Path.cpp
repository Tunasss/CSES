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

vll adj[100005];
vll p;

void dfs(int s){
    while(adj[s].size()){
        int u = adj[s].back(); 
        adj[s].pop_back();
        dfs(u);
    }
    p.pb(s);
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    int n, m; 
    cin >> n >> m;
    int in[n+1], out[n+1];

    FOR(i,0,m-1){
        int x,y; 
        cin >> x >> y;

        adj[x].pb(y);
        in[y]++, 
        out[x]++;
    }

    int a = 0, b = 0, c = 0, s1 = 0, s2 = 0;

    FOR(i,1,n){
        if (in[i] == out[i]) c++;
        if (in[i] - out[i] == 1) {
        	b++;
        	s2 = i;
        }
        if (in[i] - out[i] == -1) {
        	a++; 
        	s1 = i;
        }
    }

    if (s1 != 1 || s2 != n){
    	cout << "IMPOSSIBLE"; 
    	return 0;
    }
    if (!(c == n - 2 && a == 1 && b == 1)){
    	cout << "IMPOSSIBLE"; 
    	return 0;
    }

    dfs(1);

    if (p.size() != m + 1) {
    	cout << "IMPOSSIBLE"; 
    	return 0;
    }

    reverse(all(p));

    for (auto i: p) cout << i << " ";
    return 0;
}
