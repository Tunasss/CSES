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

vll dp(19);

void init(){
    dp[0] = 1;
    ll temp = 1;
    for (ll i = 1; i < 19; i++) {
        temp *= 9;
        dp[i] = temp;
    }
}

ll solve(ll x){
	if (x == 0) return 1;
	if (x < 0) return 0;
	str num = to_string(x);
	ll res = 0;
    for (ll i = 0; i < num.size(); i++) {
        res += dp[i];
    }
 
    ll prev = 0;
    for (ll i = 0; i < num.size(); i++) {
        ll digit = num[i] - '0';
        ll diff = num.size() - i - 1;
        ll below = prev < digit ? digit - 1 : digit;

        res += (digit == 0) ? 0 : below * dp[diff];

        if (digit == prev)
            return res;
        prev = digit;
    }
    return res + 1;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    init();
    ll a,b;
    cin >> a >> b;
    cout << solve(b) - solve(a - 1);
    
    return 0;
}
