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
 
#define debug(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
 
#define debug_end(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
 
const int N = (int)1e6 + 5;
int n, m;
vector<int> topo;
list<int> d[N];
int c[N];
 
bool check(int v, bool visit[], bool *rec)
{ 
    if (!visit[v])
    {
        visit[v] = 1;
        rec[v] = 1;
        list<int>::iterator i;
        for (i = d[v].begin(); i != d[v].end(); ++i)
        {
            if (!visit[*i] && check(*i, visit, rec))
                return true;
            else if (rec[*i])
                return true;
        }
 
    }
    rec[v] = false;  
    return false;
}
bool isCyclic()
{
    bool visit[N];
    bool rec[N];
    for (int i = 0; i < n; i++){
        visit[i] = false;
        rec[i] = false;
    }
    for (int i = 0; i < n; i++)
        if (check(i, visit, rec))
            return true;
 
    return false;
}
 
void dfs(int i) {
    if (c[i])
        return;
    c[i] = 1;
    for (int j : d[i])
        dfs(j);
    topo.pb(i);
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        d[u].pb(v);
    }
    if(isCyclic()){
        cout << "IMPOSSIBLE";
        return 0;
    }
 
    for (int i = 1; i <= n; ++i)
        dfs(i);
 
    reverse(topo.begin(), topo.end());
    
    
    for (auto x : topo){
        cout << x << " "; 
    }
    return 0;
}