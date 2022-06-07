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
#define all(v) (v).begin(), (v).end()
#define FOR(i,x,y) for(ll i = x; i <= y; i++)
#define FOS(i,x,y) for(ll i = x; i >= y; i--)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll N = 1e6 + 5;

vll graph[N], cycle;
bool c[100005];

bool DFS(int u, int p){
    c[u] = 1;
    for (auto v : graph[u]) {
        cycle.pb(v);

        if (!c[v]) {
        	if (DFS(v,u)) return 1;
        }
        else if (v != p) return 1;

        cycle.pop_back();
    }
    return 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    int n,m; 
    cin >> n >> m;

    FOR(i,1,m){
        int u,v; 
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    FOR(i,1,n){
        cycle.pb(i);
        if (!c[i] && DFS(i,0)){
            vll ans = {*cycle.rbegin()};

            for (auto j = cycle.rbegin() + 1; j != cycle.rend(); j++){
                ans.pb(*j);

                if (*j == *cycle.rbegin()) break;
            }

            cout << ans.size() << "\n";
            for (auto i: ans) cout << i << " " ;
            return 0;
        }
        cycle.pop_back();
    }
    cout << "IMPOSSIBLE";
 
    
    return 0;
}