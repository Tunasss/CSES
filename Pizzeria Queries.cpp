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

const int T = 1 << 20;
const int N = 2e5 + 5;

int n, q;

struct ST {

    ll tree[T];

    ST() { memset(tree, 0, sizeof(tree)); }

    void update(int k, int u, int id = 1, int L = 1, int R = n) {
        if (k < L || k > R) return;

        if (L == R) {
            tree[id] = u;
            return;
        }

        int M = (L + R) / 2;
        update(k, u, 2 * id, L, M);
        update(k, u, 2 * id + 1, M + 1, R);

        tree[id] = min(tree[2 * id], tree[2 * id + 1]);
    }

    ll get(int Lq, int Rq, int id = 1, int L = 1, int R = n) {
        if (L > Rq || R < Lq)
            return INT_MAX;
        if (Lq <= L && R <= Rq)
            return tree[id];

        int M = (L + R) / 2;

        return min(get(Lq, Rq, 2 * id, L, M), get(Lq, Rq, 2 * id + 1, M + 1, R));
    }
} LF, RT;


signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> q;
    FOR(i, 1, n) {
        int x; cin >> x;
        LF.update(i, x - i);
        RT.update(i, x + i);
    }

    while (q--) {
        int t;
        cin >> t;
        if (t & 1) {
            int i, x;
            cin >> i >> x;
            LF.update(i, x - i);
            RT.update(i, x + i);
        }
        else {
            int i;
            cin >> i;
            cout << min(i + LF.get(1, i), -i + RT.get(i, n)); el;
        }
    }

    return 0;
}
