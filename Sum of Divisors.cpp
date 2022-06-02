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

ll power(ll a, ll b){
    if (b == 0) return 1;
    ll ans = power(a, b / 2);
    if (b & 1) return ans * ans % MOD * a % MOD;
    return ans * ans % MOD;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll n;
    cin >> n;
    ll res = 0;
    	
    for (ll i = 1,j; i <= n; i = j){
    	ll q = n / i;
    	j = n / q + 1 ;
		ll r_J = ((((j % MOD) * ((j - 1) % MOD)) % MOD) * power(2, MOD - 2)) % MOD;
		ll r_I = ((((i % MOD) * ((i - 1) % MOD)) % MOD) * power(2, MOD - 2)) % MOD;
		ll rangeWithQuotientQ = (r_J - r_I + MOD) % MOD;
		res = (res + (q % MOD) * rangeWithQuotientQ) % MOD;
    }
    cout << res;
    return 0;
}
