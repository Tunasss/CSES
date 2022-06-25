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
ll n, q, u, v, l, timer;
vll adj[N], tin, tout;
vector<vll> up;

void dfs(ll ver, ll par) {
    tin[ver] = ++timer;
    up[ver][0] = par;

    FOR(i, 1, l) {
        if(up[ver][i - 1] != -1)
            up[ver][i] = up[up[ver][i - 1]][i - 1];
    }

    for(auto &ed : adj[ver]) {
        if(ed == par) continue;
        dfs(ed, ver);
    }

    tout[ver] = ++timer;
}

void preprocess() {
    timer = 0;
    l = floor(log2(n)) + 1;
    up.assign(n + 1, vll(l + 1, -1));
    tin.assign(n + 1, 0);
    tout.assign(n + 1, 0);
    dfs(1, -1);
}

ll find_ancestor(ll node, ll k) {
    if(k == 0) return node;
    if(node == -1) return -1;
    ll cc = 0, pw = 1;
    while(pw <= k) {
        pw *= 2;
        cc++;
    }
    pw /= 2;
    cc--;
    return find_ancestor(up[node][cc], k - pw);
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> q;
    FOR(i,2,n) {
        cin >> v;
        adj[v].pb(i);
    }
    preprocess();

    while(q--) {
        cin >> u >> v;
        cout << find_ancestor(u, v) << endl;
    }
    
    return 0;
}
