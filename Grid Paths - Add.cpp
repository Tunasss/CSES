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

typedef array<int, 2> P;
 
int const N = 2e6 + 1;
int const M = 1002;
 
ll fact[N];
ll inv[N];
 
ll mpow(ll x, ll n){
	if (n == 0) return 1;
	ll ans = mpow(x, n / 2);
	if (n & 1) return ans * ans % MOD * x % MOD;
	return ans * ans % MOD;
}
 
void init(){
	fact[0] = inv[0] = 1;
	for (ll i = 1; i < N; i++){
		fact[i] = fact[i - 1]*i % MOD;
		inv[i] = mpow(fact[i], MOD - 2);
	}
}

ll ways(P A, P B){
	return fact[B[0] - A[0] + B[1] - A[1]] * inv[B[0] - A[0]] % MOD * inv[B[1] - A[1]] % MOD;
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    init();
	int n, m; cin >> n >> m;	
	vector<P> arr(m);
	for (auto &x: arr) cin >> x[0] >> x[1];
 
	arr.push_back({n, n});
	sort(arr.begin(), arr.end());
 
	ll dp[M] = {};
 
	for (int i = 0; i <= m; i++){
		dp[i] = ways({1, 1}, arr[i]);
		for (int j = i - 1; j >= 0; j--) if (arr[j][1] <= arr[i][1])
			dp[i] = (dp[i] - dp[j]*ways(arr[j], arr[i]) % MOD + MOD) % MOD; 
	}
	cout << dp[m];

    return 0;
}
