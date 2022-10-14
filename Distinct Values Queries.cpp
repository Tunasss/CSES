#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int, int> ii;
typedef vector<ii> vii;
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

/*
const ll N = 2e5 + 5;
ll BIT[N];
int n, q, a[N], ans[N];
vii Q[N];

void add(ll pos, ll val) {
	for (ll i = pos; i <= n; i += (i & (-i)) ) {
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

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(file".INP","r",stdin);
	//freopen(file".OUT","w",stdout);
	cin >> n >> q;
	FOR(i,1,n) cin >> a[i];

	FOR(x,1,q) {
		int L, R;
		cin >> L >> R;
		Q[L].pb({R, x});
	}

	map<int, int> mymap;

	FOS(i,n,1){
		if (mymap[a[i]]) add(mymap[a[i]], -1);

        mymap[a[i]] = i;
        add(i, 1);

        for (auto x : Q[i]) ans[x.nd] = take(x.st);
	}

	FOR(i,1,q) cout << ans[i] << '\n';

	return 0;
}
*/

int const N = 2e5 + 5;
int const D = 450;

int n, q;
int a[N], ans[N];

int cnt[N] = {};
int res = 0;


struct querry {
	int l, r, id;
};
querry Q[N];

bool cmp (querry a, querry b) {
	return make_pair(a.l / D, a.r) < make_pair(b.l / D, b.r);
}
	
void compress() {
	vector<int> v(a + 1, a + n + 1);

	sort(all(v));
	v.erase(unique(all(v)), v.end());

	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(all(v), a[i]) - v.begin() + 1;
	}
}

int main() {
	cin >> n >> q;

	for (int i = 1; i <= n; i++) cin >> a[i];
	compress();

	for (int i = 1; i <= q; i++) {
		cin >> Q[i].l >> Q[i].r;

		Q[i].id = i;
	}

	sort(Q + 1, Q + q + 1, cmp);

	for (int i = 1, l = 1, r = 0; i <= q; i++) {
		while (l > Q[i].l) {
			l--;
			res += !cnt[a[l]];
			cnt[a[l]]++;
		}
		while (r < Q[i].r) {
			r++;
			res += !cnt[a[r]];
			cnt[a[r]]++;
		}

		while (l < Q[i].l) {
			cnt[a[l]]--;
			res -= !cnt[a[l]];
			l++;
		}
		while (r > Q[i].r) {
			cnt[a[r]]--;
			res -= !cnt[a[r]];
			r--;
		}
		
		ans[Q[i].id] = res;
	}

	for (int i = 1; i <= q; i++) cout << ans[i] << "\n";

	return 0;
}