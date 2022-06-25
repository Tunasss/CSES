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

const ll N = 510 * 510;
ll dp[N / 510][N];
ll n;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

  	cin >> n;
  	ll target = n * (n + 1) / 2;
  	if (target % 2) {
    	cout << 0 << endl;
    	return 0;
  	}
  	target /= 2;

 	dp[0][0] = 1;
  	for (ll i = 1; i < n; i++) {
    	for (ll j = 0; j <= target; j++) {
     	dp[i][j] = dp[i-1][j];
      	ll left = j-i;
      	if (left >= 0) (dp[i][j] += dp[i-1][left]) %= MOD;
    	}
  	}
  	cout << dp[n-1][target] << '\n';
    
    return 0;
}