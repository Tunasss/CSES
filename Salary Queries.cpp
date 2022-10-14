#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e6 + 1;

ll tree[N];
void upd(int x, int k) {
    for (int i = x; i < N; i += i & -i) tree[i] += k;
}
ll get(int x) {
    ll ans = 0;
    for (int i = x; i > 0; i -= i & -i) ans += tree[i];
    return ans;
}

struct item {
    char t;
    int a, b;
};

void compress(vector<int> &a, vector<item> &b) {
    set<int> s;
    for (auto x : a) s.insert(x);
    for (auto x : b) {
        if (x.t == '?') s.insert(x.a);
        s.insert(x.b);
    }

    vector<int> z(s.begin(), s.end());

    for (auto &x : a)
        x = lower_bound(z.begin(), z.end(), x) - z.begin() + 1;
    for (auto &x : b) {
        if (x.t == '?') x.a = lower_bound(z.begin(), z.end(), x.a) - z.begin() + 1;
        x.b = lower_bound(z.begin(), z.end(), x.b) - z.begin() + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    vector<item> que;
    while (q--) {
        char t; int a, b; cin >> t >> a >> b;
        que.push_back({t, a, b});
    }

    compress(arr, que);

    for (auto x : arr) upd(x, 1);
    for (auto x : que) {
        if (x.t == '!') {
            upd(arr[x.a - 1], -1);
            upd(x.b, 1);
            arr[x.a - 1] = x.b;
        } else {
            cout << get(x.b) - get(x.a - 1) << "\n";
        }
    }
    return 0;
}