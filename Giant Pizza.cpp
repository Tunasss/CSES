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

int const N = 2e5 + 5;
vector<int> graph[N], rg[N];
bool isvisited[N];
vector<int> topo_sort; int ids[N]; bool answers[N];
int id = 0;
int m, n;

void add_edge(int da, int a, int db, int b){
    graph[da == '+'?a + m : a].push_back(db == '+'?b : b + m);
    graph[db == '+'?b + m : b].push_back(da == '+'?a : a + m);
    rg[db == '+'?b : b + m].push_back(da == '+'?a + m : a);
    rg[da == '+'?a : a + m].push_back(db == '+'?b + m : b);
}
void topo(int v){
    if (isvisited[v]) return;
    isvisited[v] = true;

    for (auto u: graph[v]){
        topo(u);
    }
    topo_sort.push_back(v);
}
void DFS(int v){
    if (ids[v] != 0) return;
    ids[v] = id;
    for (auto u: rg[v]){
        DFS(u);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        char da, db; int a, b;
        cin >> da >> a >> db >> b;
        add_edge(da,a,db,b);
    }
    for (int i = 1; i <= 2*m; i++){
        topo(i);
    }
    reverse(topo_sort.begin(), topo_sort.end());

    for (auto v: topo_sort){
        if (ids[v] == 0) id++;
        DFS(v);
    }
    for (int i = 1; i <= m; i++){
        if (ids[i] == ids[i + m]){
            cout << "IMPOSSIBLE";
            return 0;
        }
        if (ids[i] > ids[i + m]) answers[i] = true;
        else answers[i] = false;
    }
    for (int i = 1; i <= m; ++i){
        cout << (answers[i]? '+':'-') << " ";
    }
    return 0;

    
    return 0;
}
