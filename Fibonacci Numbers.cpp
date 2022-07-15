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
#define FOR(i,x,y) for(ll i = x; i <= y; ++i)
#define FOS(i,x,y) for(ll i = x; i >= y; --i)
#define EACH(i,x) for (auto &(i) : (x))
#define el cout << '\n';
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }
 
ll x[2][2], y[2][2];
ll n;
 
void mul (ll a[2][2], ll b[2][2]){
	ll res[2][2];
	memset(res, 0, sizeof res);
 
	FOR(i,0,1){
		FOR(j,0,1){
			FOR(k,0,1){
				res[i][j] += a[i][k] * b[k][j] % MOD;
				res[i][j] %= MOD;
			}
		}
	}
	FOR(i,0,1){
		FOR(j,0,1){
			a[i][j] = res[i][j];
		}
	}
}
 
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    	
    cin >> n;
 	n++;
    x[0][1] = x[1][0] = x[1][1] = 1;
    y[0][0] = y[1][0] = 1;
 
    while(n){
        if(n & 1) mul(y, x);
        mul(x, x);
        n >>= 1;
    }
 
	cout << y[0][1];
    return 0;
}