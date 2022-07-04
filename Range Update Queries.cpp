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

void update(int id, int L, int R, int Lq, int Rq, int val) {
	if (L > Rq || R < Lq) return;
	if (Lq <= L && R <= Rq){
		tree[id] += val;
		return;
	}

	int M = (L + R) / 2;
	update(2 * id, L, M, Lq, Rq, val);
	update(2 * id + 1, M + 1, R, Lq, Rq, val);
}

ll get(int id, int L, int R, int k) {
	if (L > k || R < k)
		return 0;
	if (k <= L && R <= k)
		return tree[id];

	int M = (L + R) / 2;
	ll t1 = get(2 * id, L, M, k);
	ll t2 = get(2 * id + 1, M + 1, R, k);

	return tree[id] + t1 + t2;
}


int main() {
	cin >> n >> q;

    FOR(i,1,n) cin >> a[i];

	while(q--) {
    	int t;
    	cin >> t;
    	if (t == 1){
    		int a, b, v;
    		cin >> a >> b >> v;
    		update(1, 1, n, a, b, v);
    	}
    	else {
    		int k;
    		cin >> k;
    		cout << get(1, 1, n, k) + a[k]; el;
    	}
    }
	return 0;
}