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
typedef pair <int,int> ii;

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

ll n, res, sum = 0;
vector<ll> a;

void solve(int i, ll s) {
    if(i == n) {
        ll x = s;
        ll y = sum - s;
        if (y > x) swap(x, y);
        res = min(res, x - y);
        return;
    }
    solve(i + 1, s);
    solve(i + 1, s + a[i]);
}
//V. Chương trình chính
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    cin >> n;
    a = vector<ll>(n);

    for (int i = 0; i < n; i++) {
     	cin >> a[i];
      	sum += a[i];
    }

    res = sum;
    solve(0, 0);
    
    cout << res << endl;

    cerr << "\nTime: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
    return 0;
}
