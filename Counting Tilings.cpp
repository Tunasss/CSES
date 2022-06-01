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

ll dp[1003][1030], n,m;

void solve(ll x = 0, ll y = 0, ll mask = 0, ll next_mask = 0) {
    if (x == n)
        return;
    if (y >= m)
        (dp[x+1][next_mask] += dp[x][mask]) %= MOD;
    else
    {
        ll my_mask = 1 << y;
        if (mask & my_mask)
            solve (x, y + 1, mask, next_mask);
        else
        {
            solve (x, y + 1, mask, next_mask | my_mask);
            if (y+1 < m && ! (mask & (my_mask << 1)))
                solve (x, y + 2, mask, next_mask);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> m >> n;
    dp[0][0] = 1;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < (1 << m); j++) {
			solve(i, 0, j, 0);
		}
	}    
	cout << dp[n][0];
    
    return 0;
}
