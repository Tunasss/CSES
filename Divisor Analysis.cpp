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

const ll N = 1e5 + 5;
ll p[N], k[N];

ll power(ll a, ll b){
    if (b == 0) return 1;
    ll ans = power(a, b / 2);
    if (b & 1) return ans * ans % MOD * a % MOD;
    return ans * ans % MOD;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> p[i] >> k[i];
    ll div_cnt = 1, div_sum = 1, div_prod = 1, div_cnt2 = 1;

    for (int i = 0; i < n; i++) {
        div_cnt = div_cnt * (k[i] + 1) % MOD;
        div_sum = div_sum * (power(p[i], k[i] + 1) - 1) % MOD * power(p[i] - 1, MOD - 2) % MOD;
        div_prod = power(div_prod, k[i] + 1) * power(power(p[i], (k[i] * (k[i] + 1) / 2)), div_cnt2) % MOD;
        div_cnt2 = div_cnt2 * (k[i] + 1) % (MOD - 1);
    }
    cout << div_cnt << ' ' << div_sum << ' ' << div_prod;
    el;

    return 0;
}