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

int n, m;
vi d[100001];
ll D[100001];

ll dp(int pos) {
    if (pos == n)
        return D[pos] = 1;
    ll &rs = D[pos];
    if (rs != -1)
        return rs;
    rs = -1e17;
    for (int i : d[pos])
        rs = max(rs, dp(i) + 1);
    return rs;
}

void tk(int pos) {  
    ll rs = D[pos];
    cout << pos << ' ';
    for (int i : d[pos])
        if (D[i] + 1 == rs) {
            tk(i);
            break;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        d[a].pb(b);
    }
    memset(D, -1, sizeof D);
    if (dp(1) <= 0) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << dp(1) << '\n';
    tk(1);
    return 0;
}

