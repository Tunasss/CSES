#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <ll,ll> ii;
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

struct edge {
    ll u, v, w;
};

ll n, m;
ll cha[N], hang[N];
edge e[N];

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

ll find(ll u) {
    if (cha[u] != u) cha[u] = find(cha[u]);
    return cha[u];
}

bool join(ll u, ll v) {
    u = find(u); 
    v = find(v);
    if (u == v) return false;
    if (hang[u] == hang[v]) hang[u]++;
    if (hang[u] < hang[v]) cha[u] = v;
    else cha[v] = u;
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> m;
    FOR(i,1,m) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }

    sort(e + 1, e + 1 + m, cmp);

    FOR(i,1,n){
        cha[i] = i;
        hang[i] = 0;
    }
    ll res = 0;

	FOR(i,1,m) {
        if (join(e[i].u, e[i].v)) {
            res += e[i].w;
        }
    }
    ll root = find(1);

	FOR(i,2,n){
		if (find(i) != root){
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	cout << res;
}