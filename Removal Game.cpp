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

ll n, x[N], sum = 0;
ll dp[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

  	cin >> n;

  	FOR (i,0,n - 1){
  		ll v;
    	cin >> v;
    	x[i] = v;
    	sum += v;
  	}

  	for (ll l = n-1; l >= 0; l--) {
    	for (ll r = l; r < n; r++) {
      		if (l == r) dp[l][r] = x[l];
     		else {
				dp[l][r] = max(x[l] - dp[l + 1][r], x[r] - dp[l][r - 1]);
      		}
    	}
  	}
  	cout << (sum + dp[0][n - 1]) / 2;
    
    return 0;
}
