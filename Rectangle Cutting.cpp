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

const ll N = 505;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll a, b;
  	cin >> a >> b;
  	ll dp[N][N];

  	for (ll i = 0; i <= a; i++) {
    	for (ll j = 0; j <= b; j++) {
      		if (i == j) dp[i][j] = 0;
  			else dp[i][j] = LLONG_MAX;

		for (ll k = 1; k < i; k++) 
	  		dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
		
		for (ll k = 1; k < j; k++) 
	  		dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
      	}
    }
  	cout << dp[a][b] << endl;
    
    return 0;
}
