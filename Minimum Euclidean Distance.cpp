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
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;

/*
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }
*/

#define int long long
const ll N = 2e5 + 5;

struct point {
	int x, y;
} a[N];

int s = 50;

bool cmp(const point &a, const point &b) {
	return a.x * a.y < b.x * b.y;
}

int calc(point x, point y) {
	return (x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(file".INP","r",stdin);
	//freopen(file".OUT","w",stdout);

	int ans = (int)1e20;
	int n; cin >> n;

	FOR(i, 1, n)  cin >> a[i].x >> a[i].y;

	sort(a + 1, a + n + 1, cmp);

	FOR(i, 1, n) {
		for (int j = i + 1; j <= n && j <= i + s; j++) {
			ans = min(ans, calc(a[i], a[j]));
		}
	}

	cout << ans; el;
}