#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <ll, ll> ii;
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

const int N = 3e5 + 5;  
const int T = 1 << 21;

int n, q, a[N] = {};
ll tree[T] = {};
ii lazy[T] = {};

void build(int id, int L, int R) {
    if (L == R) {
        tree[id] = a[L];
        return;
    }

    int M = (L + R) / 2;
    build(2 * id, L, M);
    build(2 * id + 1, M + 1, R);

    dbg(id), dbg(L), dbge(R);

    tree[id] = tree[2 * id] + tree[2 * id + 1];
}

void lazy_update(int id, int L, int R) {
    ll a = lazy[id].st;
    ll b = lazy[id].nd;

    tree[id] += 1LL * a * (R + L) * (R - L + 1) / 2;
    tree[id] += 1LL * b * (R - L + 1);

    if (L != R) {
        lazy[2 * id].st += a;
        lazy[2 * id].nd += b;
        lazy[2 * id + 1].st += a;
        lazy[2 * id + 1].nd += b;
    }

    lazy[id] = {0, 0};
}

void update(int id, int L, int R, int u, int v) {
    lazy_update(id, L, R);

    if (L > v || R < u) return;

    if (L >= u && R <= v) {
        lazy[id].st = 1;
        lazy[id].nd = -u + 1;
        lazy_update(id, L, R);

        return;
    }

    int M = (L + R) / 2;
    update(2 * id, L, M, u, v);
    update(2 * id + 1, M + 1, R, u, v);

    tree[id] = tree[2 * id] + tree[2 * id + 1];
}

ll get(int id, int L, int R, int u, int v) {
    lazy_update(id, L, R);

    if (L > v || R < u)
        return 0;
    if (u <= L && R <= v)
        return tree[id];

    int M = (L + R) / 2;
    ll t1 = get(2 * id, L, M, u, v);
    ll t2 = get(2 * id + 1, M + 1, R, u, v);

    return t1 + t2;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    build(1, 1, n);

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            update(1, 1, n, a, b);
        }
        else {
            cout << get(1, 1, n, a, b); el;
        }
    }

    return 0;
}