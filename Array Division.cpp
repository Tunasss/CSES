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
#define FOR(i,x,y) for(ll i = x; i <= y; i++)
#define FOS(i,x,y) for(ll i = x; i >= y; i--)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    int n, k; 
    cin >> n >> k;
	vector<ll> a(n);
	ll max_sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		max_sum = max_sum + a[i];
	}
	
	ll lo = 0, hi = max_sum, ans = 0;
	auto works = [&] (ll mid) {
		int groups = 0;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > mid) {
				return false;
			}
			if (sum + a[i] > mid) {
				++groups;
				sum = 0;
			}
			sum += a[i];
		}
		if (sum > 0) {
			++groups;
		}
		return groups <= k;
	};
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (works(mid)) {
			hi = mid - 1;
			ans = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << ans << '\n';
    
    return 0;
}
