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

const ll N = 2e6 + 5;
#define pii pair<long long,int>
const ll oo = LLONG_MAX;

vector<pii> adj[N];
ll ways[N];
int maxf[N], minf[N];
bool vis[N];

int n,m;

void Dijkstra(){
    priority_queue<pair<int, int>> myque;
    myque.push({0,1});

    while(myque.size()){
        pii pu = myque.top();
        myque.pop();
        int u = pu.nd;
        ll wu = -pu.st;

        if (u == 2 * n){
            cout << wu;
            return;
        } 
        vis[u] = 1;

        for (auto pv : adj[u]){
            int v = pv.st;
            if (vis[v]) continue;
            ll wv = pv.nd;
            myque.push({-wu-wv,v});
        }

        while(!myque.empty() && vis[myque.top().second]) myque.pop();
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u + n].push_back({v + n, w});
        adj[u].push_back({v + n, w / 2});
        adj[u].push_back({v, w});
    }

    Dijkstra();
    return 0;
}