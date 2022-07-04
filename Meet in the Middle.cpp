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
#define el cout << endl;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll N = 1e5 + 5;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    

    int n, x; cin >> n >> x;
    int m1 = n / 2, m2 = n - m1;
    int arr1[m1], arr2[m2];
    for (int i = 0; i < m1; i++) cin >> arr1[i];
    for (int i = 0; i < m2; i++) cin >> arr2[i];

    vector<ll> sum1, sum2;
    for (int i = 0; i < (1 << m1); i++) { 
        ll cur = 0;
        for (int j = 0; j < m1; j++)
            if (i & (1 << j))
                cur += arr1[j];
        sum1.push_back(cur);
    }
    for (int i = 0; i < (1 << m2); i++) { 
        ll cur = 0;
        for (int j = 0; j < m2; j++)
            if (i & (1 << j))
                cur += arr2[j];
        sum2.push_back(cur);
    }
    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());

    ll ans = 0;
    for (ll s1 : sum1)
        ans += upper_bound(sum2.begin(), sum2.end(), x - s1) - lower_bound(sum2.begin(), sum2.end(), x - s1);
    cout << ans;

    return 0;
}