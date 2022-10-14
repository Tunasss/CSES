#include <bits/stdc++.h>
using namespace std;
#define FOR(i,x,y) for(ll i = x; i <= y; ++i)
#define FOS(i,x,y) for(ll i = x; i >= y; --i)
typedef long long ll;
#define el cout << '\n';

const int N = 2e5 + 5;

struct range {
    int l, r, id;
} a[N];

int BIT[N << 1], X[N << 1];
int n, m, ans1[N], ans2[N], timer;

bool cmp (range A, range B) {
    return A.r != B.r ? A.r < B.r : A.l > B.l;
}

void add(int pos) {
    for (int i = pos; i <= timer; i += (i & (-i)) ) {
        BIT[i]++;
    }
}

ll sum(int pos) {
    ll res = 0;
    for (int i = pos; i >= 1; i -= (i & (-i)) ) {
        res += BIT[i];
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    FOR(i, 1, n) {
        cin >> a[i].l >> a[i].r;
        X[++timer] = a[i].l;
        X[++timer] = a[i].r;
        a[i].id = i;
    }

    sort(X + 1, X + timer + 1);

    FOR(i, 1, n) {
        a[i].l = lower_bound(X + 1, X + timer + 1, a[i].l) - X;
        a[i].r = lower_bound(X + 1, X + timer + 1, a[i].r) - X;
    }

    sort(a + 1, a + n + 1, cmp);

    memset(BIT, 0, sizeof BIT);
    FOR(i, 1, n) {
        ans1[a[i].id] = sum(timer) - sum(a[i].l - 1);
        add(a[i].l);
    }

    memset(BIT, 0, sizeof BIT);
    FOS(i, n, 1) {
        ans2[a[i].id] = sum(a[i].l);
        add(a[i].l);
    }

    FOR(i, 1, n) cout << ans1[i] << " "; el;
    FOR(i, 1, n) cout << ans2[i] << " "; el;

    return 0;
}
