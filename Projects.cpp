#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int, int> ii;
typedef pair <ii, ll> iii;
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

/*
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }
*/

// #define int long long
const ll N = 2e5 + 5;

iii a[N];
ll dp[N] = {};
int n;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i].st.nd >> a[i].st.st >> a[i].nd;
    }

    sort(a, a + n);
    memset(dp, 0, sizeof(dp));

    dp[0] = a[0].nd;

    for (int i = 1; i < n; ++i) {
        int L = 0;
        int R = i - 1;
        int id = -1;

        int num = a[i].st.nd;

        while (L <= R) {
            int M = (L + R) / 2;
            if (a[M].st.st < num) {
                L = M + 1;
                id = M;
            }
            else {
                R = M - 1;
            }
        }

        if (id == -1) dp[i] = max(dp[i - 1], a[i].nd);
        else dp[i] = max(dp[i - 1], dp[id] + a[i].nd);
    }

    cout << dp[n - 1];

    return 0;
}