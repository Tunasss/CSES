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

const ll N = 2e5 + 5;

ll bit[N];
ll n;

void update (ll i, ll val) {
	for (; i <= n; i += (i & (-i))) {
		bit[i] = (bit[i] + val) % MOD;
	}
}

ll query (ll i) {
	ll res = 0;
	for (; i; i -= (i & (-i))) {
		res = (res + bit[i]) % MOD;
	}
	return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n;
	map<ll, ll> m;
	vll a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		m[a[i]]++;
	}
	ll co = 0;
	for (auto &cur : m) {
		cur.second = ++co;
	}
	for (ll &x : a) {
		x = m[x];
	}
	ll sol = 0;
	for (ll x : a) {
		ll subseq = 1 + query(x - 1);
		sol = (sol + subseq) % MOD;
		update(x, subseq);
	}
	cout << sol << '\n';
    
    return 0;
}