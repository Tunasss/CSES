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

const ll N = 1e6 + 5;
ll fc[N], inv[N];

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

ll C(int m, int n)
{
    if (m > n)
        return 0;
    return fc[n] * inv[m] % MOD * inv[n - m] % MOD;
}

void init(){
    fc[0] = inv[0] = 1; 
    for (ll i = 1; i <= 1000001; i++){
        fc[i] = fc[i - 1] * i % MOD;
        inv[i] = power(fc[i], MOD - 2);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    init();
    ll t; cin >> t;
    while(t--){
		ll n, r;
		cin >> n >> r;
		cout << C(r,n) << '\n';
    }
    return 0;
}
