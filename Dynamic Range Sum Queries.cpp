/*
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

int n, q, a[N];
ll tree[T];

void build(int id, int L, int R) {
	if (L == R) {
		tree[id] = a[L];
		return;
	}

	int M = (L + R) / 2;
	build(2 * id, L, M);
	build(2 * id + 1, M + 1, R);

	tree[id] = tree[2 * id] + tree[2 * id + 1];
}

void update(int id, int L, int R, int k, int u) {
	if (k < L || k > R) return;

	if (L == R) {
		tree[id] = u;
		return;
	}

	int M = (L + R) / 2;
	update(2 * id, L, M, k, u);
	update(2 * id + 1, M + 1, R, k, u);

	tree[id] = tree[2 * id] + tree[2 * id + 1];
}

ll get(int id, int L, int R, int Lq, int Rq) {
	if (L > Rq || R < Lq)
		return 0;
	if (Lq <= L && R <= Rq)
		return tree[id];

	int M = (L + R) / 2;
	ll t1 = get(2 * id, L, M, Lq, Rq);
	ll t2 = get(2 * id + 1, M + 1, R, Lq, Rq);

	return t1 + t2;
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

	cin >> n >> q;
	FOR(i, 1, n) cin >> a[i];

	build(1, 1, n);

	cerr << "\n";
	print();

	while (q--) {
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 1){
			update(1, 1, n, a, b);
			cerr << "\n";
			print();
		}
		else {
			cout << get(1, 1, n, a, b); el;
		}
	}

	return 0;
}

*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int, int> ii;
#define file "TEST"
#define st first
#define nd second
#define pb push_back
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

/*
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }
*/

#define int long long
const ll N = 2e5 + 5;
const ll D = 450;

int n, q;
int a[N], sqd[N / D + 1];

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q;

	FOR(i, 1, n) {
		cin >> a[i];
	}

	FOR(i, 1, n) {
		sqd[i / D] += a[i];
	}

	while (q--) {
		int t; cin >> t;

		if (t == 1) {
			int k, val;
			cin >> k >> val;
			
			sqd[k / D] -= a[k];
			a[k] = val;
			sqd[k / D] += a[k];
		}

		if (t == 2) {
			int x, y;
			cin >> x >> y;

			ll ans = 0;

			for (int i = x; i <= y;) {
				int CurBlock = i / D;

				if (x <= CurBlock * D && CurBlock * D + D - 1 <= y) {
					ans += sqd[CurBlock];
					i += D;
				}
				
				else {
					ans += a[i];
					i++;
				}
			}
			cout << ans; el;
		}
	}
	return 0;
}
