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

const ll N = 1e5 + 5;
const ll M = 105;
ll n, m;
ll dp[N][M];

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
  
  	cin >> n >> m;
  	ll check;
  	cin >> check;

  	if (check == 0){
   		for(ll i = 0; i < M; i++) dp[0][i] = 1; 
  	}
	else dp[0][check] = 1;

  	for (ll i = 1; i < n; i++) {
    	ll x;
    	cin >> x;
    	if (x == 0) {
      		for (ll j = 1; j <= m; j++) {
				for (ll k : {j - 1, j , j + 1}) {
	 				if (k >= 1 && k <= m) (dp[i][j] += dp[i-1][k]) %= MOD;
	  				}
				}
      		}
    	else {
      	for (ll k : {x - 1, x ,x + 1}) {
			if (k >= 1 && k <= m) (dp[i][x] += dp[i-1][k]) %= MOD;
      		}
    	}
  	}
  	ll ans = 0;
  	for (ll j = 1; j <= m; j++) {
  		(ans += dp[n-1][j]) %= MOD;
  	}
 	cout << ans << endl;
    
    return 0;
}
