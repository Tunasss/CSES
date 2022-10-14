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

int n, m, k, d[N];
ll tree[T];

void build(int id, int L, int R) {
    if (L == R) {
        tree[id] = 1;
        return;
    }

    int M = (L + R) / 2;
    build(2 * id, L, M);
    build(2 * id + 1, M + 1, R);

    tree[id] = tree[2 * id] + tree[2 * id + 1];
}

void update(int id, int L, int R, int k) {
    if (k < L || k > R) return;

    if (L == R) {
        tree[id] = 0;
        return;
    }

    int M = (L + R) / 2;
    update(2 * id, L, M, k);
    update(2 * id + 1, M + 1, R, k);

    tree[id] = tree[2 * id] + tree[2 * id + 1];
}

ll get_sum(int id, int L, int R, int Lq, int Rq) {
    if (L > Rq || R < Lq)
        return 0;
    if (Lq <= L && R <= Rq)
        return tree[id];

    int M = (L + R) / 2;
    return get_sum(2 * id, L, M, Lq, Rq) + get_sum(2 * id + 1, M + 1, R, Lq, Rq);
}

int get(int id, int L, int R, int k) {
    if (tree[id] < k)
        return - 1;
    if (L == R)
        return L;

    int M = (L + R) / 2;

    if (tree[id * 2] >= k)
        return get(2 * id, L, M, k);

    return get(2 * id + 1, M + 1, R, k - tree[id * 2]);
}

void print(int id = 1, int L = 1, int R = n) {
    if (L == R) {
        dbg(id), dbg(L), dbg(R);
        dbge(tree[id]);
        return;
    }
    int M = (L + R) / 2;
    print(2 * id, L, M);
    print(2 * id + 1, M + 1, R);
}


signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> k;
    k++;

    build(1, 1, n);

    // cerr << "\n";
    // print();

    int x = 0, m = n;

    while (m > 0) {
        int nx = get_sum(1, 1, n, 1, x) + k % m;

        if (nx == 0) nx = m;

        int ans = get(1, 1, n, nx);

        if (ans < 0) {
            nx = (k % m) - get_sum(1, 1, n, x + 1, n);
            ans = get(1, 1, n, nx);
        }

        cout << ans << ' ';
        update(1, 1, n, ans);

        x = ans;
        m--;
        d[ans] = 1;
    }

    return 0;
}
