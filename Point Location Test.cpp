#include <bits/stdc++.h>
#include <unordered_map>
#include <complex>
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
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }\

#define X real()
#define Y imag()

typedef complex<ll> point;

void solve() {
	array<array<int, 2>, 4> p;

	cin >> p[1][0] >> p[1][1] >> p[2][0] >> p[2][1] >> p[3][0] >> p[3][1];
	
	point A = {p[1][0], p[1][1]}, B = {p[2][0], p[2][1]}, C = {p[3][0], p[3][1]};
	point AC = C - A, CB = B - C;
	ll tvh = (conj(AC) * CB).Y;
	if (tvh < 0) cout << "LEFT";
	else if (tvh > 0) cout << "RIGHT";
	else cout << "TOUCH";
	el;
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(file".INP","r",stdin);
	//freopen(file".OUT","w",stdout);

	ll t = 1;
	if (true) cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}