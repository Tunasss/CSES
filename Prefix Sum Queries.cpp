#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;
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
#define el cout << endl;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const int N = 1 << 19;

int n, q, type, k, u, a, b;
int v[N];
pair<ll, ll> tree[N];

void build(int id, int L, int R) {
	if (L > R) return;

	if (L == R) {
		tree[id].st = v[L];
		tree[id].nd = max(0, v[L]);
		return;
	}

	int M = (L + R) / 2;
	build(2 * id, L, M);
	build(2 * id + 1, M + 1, R);

	tree[id].st = tree[2 * id].st + tree[2 * id + 1].st;

	tree[id].nd = max(tree[2 * id].nd, tree[2 * id].st + tree[2 * id + 1].nd);
}

void update(int id, int L, int R, int k, int u) {
	if (L > R || k < L || k > R) return;

	if (L == R) {
		if (L != k) return;
		tree[id].st = u;
		tree[id].nd = max(0, u);
		return;
	}

	int M = (L + R) / 2;
	update(2 * id, L, M, k, u);
	update(2 * id + 1, M + 1, R, k, u);

	tree[id].st = tree[2 * id].st + tree[2 * id + 1].st;

	tree[id].nd = max(tree[2 * id].nd, tree[2 * id].st + tree[2 * id + 1].nd);
}

ll querySum(int id, int L, int R, int a, int b) {
	if (L > R || b < L || a > R || a > b) return 0;

	if (a <= L && R <= b) {
		return tree[id].st;
	}

	int M = (L + R) / 2;

	if (b < M) {
		return querySum(2 * id, L, M, a, b);
	}

	if (a > M) {
		return querySum(2 * id + 1, M + 1, R, a, b);
	}

	ll sum = querySum(2 * id, L, M, a, b) + querySum(2 * id + 1, M + 1, R, a, b);

	return sum;
}

ll queryPre(int id, int L, int R, int a, int b) {
	if (L > R || b < L || a > R || a > b) return 0;

	if (a <= L && R <= b) {
		return tree[id].nd;
	}

	int M = (L + R) / 2;

	if (b < M) {
		return queryPre(2 * id, L, M, a, b);
	}

	if (a > M) {
		return queryPre(2 * id + 1, M + 1, R, a, b);
	}

	ll pre = max(queryPre(2 * id, L, M, a, b), querySum(2 * id, L, M, a, b) + queryPre(2 * id + 1, M + 1, R, a, b));

	return pre;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

	cin >> n >> q;

	FOR(i,0,n - 1) cin >> v[i];

	build(1,0,n - 1);

	while (q--) {
		cin >> type;

		if (type == 1) {
			cin >> k >> u;
			k--;
			update(1,0,n - 1,k,u);
		}

		else {
			cin >> a >> b;
			a--; b--;
			cout << queryPre(1,0,n - 1,a,b) << "\n";
		}
	}

	return 0;
}