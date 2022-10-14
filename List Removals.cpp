#include <bits/stdc++.h>
#include <unordered_map>
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
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll N = 2e5 + 5;
ll BIT[N];

void build(ll pos) {
    for (ll i = pos; i <= N; i += (i & (-i)) ) {
        BIT[i]++;
    }
}

void add(ll pos, ll val) {
    for (ll i = pos; i <= N; i += (i & (-i)) ) {
        BIT[i] += val;
    }
}

ll take(ll pos) {
    ll res = 0;
    for (ll i = pos; i >= 1; i -= (i & (-i)) ) {
        res += BIT[i];
    }
    return res;
}


int n, a[N], b[N];

int bs(ll x, ll L = 1, ll R = n) {
    if (L == R) return L;
    int M = (L + R) / 2;
    if (take(M) >= x) return bs(x, L, M);
    return bs(x, M + 1, R);
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    cin >> n;

    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n) cin >> b[i];
    FOR(i,1,n) build(i);

    FOR(i,1,n) {
        cout << a[bs(b[i])] << ' ';
        
        add(bs(b[i]), -1);
    }
    return 0;
}
