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

int const N = 1e5 + 5;
vector<int> graph[N], rg[N], topo_order;
bool isvisited[N]; int ids[N];
int id = 0, n, m;
 
void topo(int v){
    if(isvisited[v]) return;
    isvisited[v] = true;
 
    for (auto u: graph[v]) topo(u);
 
    topo_order.push_back(v);
}
 
void DFS(int v){
    if (ids[v] != 0) return;
    ids[v] = id;
 
    for (auto u: rg[v]) DFS(u);
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> m;
    
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
 
        graph[u].push_back(v);
        rg[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) topo(i);
 
    reverse(topo_order.begin(), topo_order.end());
 
    for (auto i: topo_order){
        if (ids[i] == 0) id++;
        DFS(i);
    }
 
    if (id == 1) cout << "YES";
    else {
        cout << "NO" << endl;
        int a, b;
        a = topo_order.front();
 
        for (auto i: topo_order){
            if (ids[i] != ids[a]){
                b = i;
                break;
            }
        }
        if (ids[b] < ids[a])cout << a << " " << b;
        else cout << b << " " << a; 
    }
    
    return 0;
}
