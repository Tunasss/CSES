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

const ll N = 5005;
ll dp[N][N];
str a, b;
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    memset(dp, 9999999, sizeof dp);
  	cin >> a >> b;

  	dp[0][0] = 0;
  	for (ll i = 0; i <= a.size(); i++) {
    	for (ll j = 0; j <= b.size(); j++) {
		    if (i) {
				dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
		    }
		    if (j) {
				dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
		    }
		    if (i && j) {
				dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (a[i-1] != b[j-1]));
		    }
    	}
  	}
  	cout << dp[a.size()][b.size()] << endl;
    
    return 0;
}
