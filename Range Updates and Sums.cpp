#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define PB push_back
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define fi   first
#define se   second
#define BIT(x, i) (((x) >> (i)) & 1)
using namespace std;

/** END OF TEMPLATE **/

const int mxN = 1e5 + 5;
const ll INF = 1e18;

struct segTree {
    vector<ll> st, laz, asg;
    vector<bool> mark;
    int siz;
    segTree(int t) {
        siz = t * 4 + 1;
        st.resize(siz, 0);
        asg.resize(siz, INF);
        laz.resize(siz, 0);
    }

    void Increase(int id, int l, int r, ll d) {
        st[id] += (r - l + 1) * d;
        laz[id] += d;
    }

    void Assign(int id, int l, int r, ll d) {
        st[id] = (r - l + 1) * d;
        asg[id] = d;
        laz[id] = 0;
    }

    void down(int id, int l, int r) {
        if (asg[id] != INF) {
            int mid = (l + r) >> 1;
            Assign(id << 1, l, mid, asg[id]);
            Assign(id << 1 | 1, mid + 1, r, asg[id]);
            asg[id] = INF;
        }
        if (laz[id] != 0) {
            int mid = (l + r) >> 1;
            Increase(id << 1, l, mid, laz[id]);
            Increase(id << 1 | 1, mid + 1, r, laz[id]);
            laz[id] = 0;
        }
    }

    void update1(int id, int l, int r, int u, int v, int d) {
        if (l != r) down(id, l, r);
        if (u > r || v < l) return;
        if (u <= l && r <= v) {
            Increase(id, l, r, d);
            return;
        }
        int mid = (l + r) >> 1;
        update1(id << 1, l, mid, u, v, d);
        update1(id << 1 | 1, mid + 1, r, u, v, d);
        st[id] = st[id << 1] + st[id << 1 | 1];
    }

    void update2(int id, int l, int r, int u, int v, int d) {
        if (l != r) down(id, l, r);
        if (u > r || v < l) return;
        if (u <= l && r <= v) {
            Assign(id, l, r, d);
            return;
        }
        int mid = (l + r) >> 1;
        update2(id << 1, l, mid, u, v, d);
        update2(id << 1 | 1, mid + 1, r, u, v, d);
        st[id] = st[id << 1] + st[id << 1 | 1];
    }

    ll get(int id, int l, int r, int u, int v) {
        if (l != r) down(id, l, r);
        if (u > r || v < l) return 0;
        if (u <= l && r <= v) return st[id];
        int mid = (l + r) >> 1;
        ll tmp = get(id << 1, l, mid, u, v)
                 + get(id << 1 | 1, mid + 1, r, u, v);
        st[id] = st[id << 1] + st[id << 1 | 1];
        return tmp;
    }
};

int n, q;

int main()
{
    FastIO;
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >> n >> q;
    segTree ST(n);
    FOR(i, 1, n) {
        int x; cin >> x;
        ST.update1(1, 1, n, i, i, x);
    }

    while (q--) {
        int state; cin >> state;
        if (state == 1) {
            int u, v, d; cin >> u >> v >> d;
            ST.update1(1, 1, n, u, v, d);
        }
        else if (state == 2) {
            int u, v, d; cin >> u >> v >> d;
            ST.update2(1, 1, n, u, v, d);
        }
        else {
            int u, v; cin >> u >> v;
            cout << ST.get(1, 1, n, u, v) << '\n';
        }
    }

    return 0;
}

/*
5 3
1 2 3 4 5
1 2 4 1
2 2 3 1
3 1 5
*/