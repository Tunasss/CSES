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
#define lb lower_bound
#define ub upper_bound
#define vll vector<ll>
#define vi vector<int>
#define all(v) (v).begin(), (v).end()
#define FOR(i,x,y) for(ll i = x; i <= y; ++i)
#define FOS(i,x,y) for(ll i = x; i >= y; --i)
#define EACH(i,x) for (auto &(i) : (x))
#define el cout << '\n';
const ll MOD = 1000000007;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;

/*
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }
*/

#define int long long
const ll N = 1e6 + 5;
ll fac[N], inv[N];

ll mpow(ll a, ull b){
    if (b == 0) return 1;
    ll ans = mpow(a, b / 2);
    if (b & 1) return ans * ans % MOD * a % MOD;
    return ans * ans % MOD;
}

void solve() {
	str s;
	cin >> s;

	int a[26] = {0};
	for (auto i : s) a[i - 'a']++;

	int ans = fac[s.size()];
	FOR(i, 0, 25) {
		(ans *= inv[a[i]]) %= MOD;
	}
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(file".INP","r",stdin);
	//freopen(file".OUT","w",stdout);

	fac[0] = 1;
	inv[0] = 1;

	FOR(i, 1, (ll)1e6) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = mpow(fac[i], MOD - 2);
	}

	ll t = 1;
	while (t--) {
		solve();
	}

	return 0;
}