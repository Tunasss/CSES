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

/*
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }
*/

//#define int long long
const ll N = 2e5 + 5;
int n, k, a[N];
signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];

	multiset <int> LS, RS;
	ll lsum = 0, rsum = 0;

	for (int i = 0; i < k - 1; i++) {
		RS.insert(a[i]);
		rsum += a[i];
	}

	for (int i = k - 1; i < n; i++) {
		rsum += a[i];
		RS.insert(a[i]);
		while (RS.size() > k / 2) {
			int v = *RS.begin();
			RS.erase(RS.begin());

			rsum -= v;
			lsum += v;

			LS.insert(v);
		}

		while (LS.size() && RS.size() && *LS.rbegin() > *RS.begin()) {
			int u = *LS.rbegin();
			int v = *RS.begin();
			LS.erase(LS.find(u));
			RS.erase(RS.begin());
			lsum -= u;
			lsum += v;
			rsum -= v;
			rsum += u;
			LS.insert(v);
			RS.insert(u);
		}

		ll median = *LS.rbegin();
		ll res = LS.size() * median - lsum + rsum - RS.size() * median;
		cout << res << ' ';

		if (RS.count(a[i - k + 1])) {
			rsum -= a[i - k + 1];
			RS.erase(RS.find(a[i - k + 1]));
		}
		else {
			lsum -= a[i - k + 1];
			LS.erase(LS.find(a[i - k + 1]));
		}
	}
	el;

	return 0;
}
