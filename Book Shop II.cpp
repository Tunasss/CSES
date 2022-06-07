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

const ll N = 105; 

ll n, x, h[N], s[N], k[N];
ll dp[SIZE];

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    
    cin >> n >> x;
    FOR(i,0,n - 1) cin >> h[i];
    FOR(i,0,n - 1) cin >> s[i];
    FOR(i,0,n - 1) cin >> k[i];

    fill(dp + 1, dp + x + 1, -1);

    FOR(i,0,n - 1){
    	for(ll b = 1; k[i] > 0; b++){
    		ll amnt = min(b, k[i]);
            k[i] -= b;
            ll price = amnt * h[i];
            ll pages = amnt * s[i];
            for(ll j = x; j >= price; j--)
                if(dp[j - price] != -1)
                    dp[j] = max(dp[j], dp[j - price] + pages);
    	}
    }
    FOR(i,1,x){
        dp[i] = max(dp[i], dp[i-1]);
    }
    cout << dp[x];
    return 0;
}
