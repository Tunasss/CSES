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
    ll ans = 1 % MOD;
    for (; b; b >>= 1)
    {
        if (b & 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll n;
    cin >> n;
    if (n & 1) {
    	cout << 0;
    	return 0;
    }
    n /= 2;
    vll res(n + 1);
    res[0] = 1;
    FOR(i,1,n){
    	res[i] = ((((4 * i - 2) * power(i + 1, MOD - 2)) % MOD) * res[i - 1]) % MOD;
    }
    cout << res[n];
    return 0;
}
