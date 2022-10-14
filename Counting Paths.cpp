#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int, int> ii;
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

//#define int long long
const ll N = 2e5 + 5;

int anc[30][N];
int deep[N];
int dp[N];

vector<int> adj[N];

void DFS1(int n, int par, int d)
{
    anc[0][n] = par;
    deep[n] = d;

    for (int v : adj[n]) {
        if (v != par) {
            DFS1(v, n, d + 1);
        }
    }
}

void DFS2(int n, int par)
{
    for (int v : adj[n]) {
        if (v != par) {
            DFS2(v, n);
            dp[n] += dp[v];
        }
    }
}

int LCA(int a, int b)
{
    if (deep[a] < deep[b]) swap(a, b);

    for (int i = 20; i >= 0; i--) {
        if (deep[anc[i][a]] >= deep[b]) {
            a = anc[i][a];
        }
    }

    if (a == b) return a;

    for (int i = 20; i >= 0; i--) {
        if (anc[i][a] != anc[i][b]) {
            a = anc[i][a];
            b = anc[i][b];
        }
    }
    return anc[0][a];
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    deep[0] = -1;
    DFS1(1, 0, 0);

    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= n; j++)
            anc[i][j] = anc[i - 1][anc[i - 1][j]];

    while (q--) {
        int x, y;
        cin >> x >> y;
        dp[x]++;
        dp[y]++;
        int tmp = LCA(x, y);
        dp[tmp]--;
        dp[anc[0][tmp]]--;
    }

    DFS2(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << ' ';
    }
    return 0;
}
