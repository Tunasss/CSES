#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass
 
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
 
#define all(v) (v).begin(), (v).end()
#define fto(i,x,y) for(ll i = x; i <= y; i++)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
 
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
 
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
 
 
vector<ll> graph[200005];
ll danhdau[200005];
 
ll maxx = INT_MIN, maxx_node = 0;
 
void DFS(ll v, ll d)
{
    danhdau[v] = 1;
 
    if (d > maxx) {
        maxx = d;
        maxx_node = v;
    }
 
    for (ll u : graph[v])
        if (!danhdau[u])
            DFS(u, d + 1);
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);
    ll a,b,n;
    cin >> n;
 
    for (ll i = 1; i <= n - 1; i++) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
 
    maxx = INT_MIN;
    DFS(1, 0);
 
    //Phai resset de co the thuc hien lan chay BFS thu 2
    for (ll i = 1; i <= n; i++) danhdau[i] = 0; 
    
    maxx = INT_MIN;
    DFS(maxx_node, 0);
    
    cout << maxx;
 
    return 0;
}