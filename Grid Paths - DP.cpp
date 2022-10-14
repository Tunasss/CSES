#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
/*
       _,    _   _    ,_
  .o888P     Y8o8Y     Y888o.
 d88888      88888      88888b
d888888b_  _d88888b_  _d888888b
8888888888888888888888888888888
8888888888888888888888888888888
YJGS8P"Y888P"Y888P"Y888P"Y8888P
 Y888   '8'   Y8P   '8'   888Y
  '8o          V          o8'
*/
//Tunass

//I. Định nghĩa các kiểu dữ liệu
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int, int> ii;

//II. Định nghĩa các từ hay dùng (snippet)
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
#define fto(i,x,y) for(ll i = x; i <= y; i++)

//III. Định nghĩa các MAX của kiểu dữ liệu
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;

//IV. Định nghĩa hàm Debug
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;

//IV. Định nghĩa hàm sinh số Random từ L đến R
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

//V. Chương trình chính
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    int n;
    cin >> n;

    vector<vector<char>>grid;
    vecor<vector<int>>dp;

    for (int i = 0; i < n; i++)
    {
        vector<int>q(n, 0);
        vector<char>p(n);

        for (auto &x : p)
            cin >> x;
        grid.pb(p);
        dp.pb(q);
    }
    if (grid[n - 1][n - 1] != '*')
        dp[n - 1][n - 1] = 1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (grid[i][n - 1] != '*')
            dp[i][n - 1] = dp[i + 1][n - 1];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (grid[n - 1][i] != '*')
            dp[n - 1][i] = dp[n - 1][i + 1];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (grid[i][j] != '*')
                dp[i][j] = (dp[i][j + 1] + dp[i + 1][j]) % MOD;
        }
    }

    cout << dp[0][0] << endl;

    cerr << "\nTime: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
    return 0;
}
