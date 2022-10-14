#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int, int> ii;
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

int res = 0;
string s;
bool mark[7][7];

bool isValid(int row, int col)
{
    return row >= 0 && col >= 0 && row < 7 && col < 7 && !mark[row][col];
}

void backtrack(int row, int col, int idx)
{
    if (row == 6 && col == 0) {
        res += (idx == 48);
        return;
    }

    mark[row][col] = true;

    if ((s[idx] == 'U' || s[idx] == '?') && row && !mark[row - 1][col]) {
        if (!(!isValid(row - 2, col) && isValid(row - 1, col - 1) && isValid(row - 1, col + 1))) {
            backtrack(row - 1, col, idx + 1);
        }
    }

    if ((s[idx] == 'R' || s[idx] == '?') && col < 6 && !mark[row][col + 1]) {
        if (!(!isValid(row, col + 2) && isValid(row - 1, col + 1) && isValid(row + 1, col + 1))) {
            backtrack(row, col + 1, idx + 1);
        }
    }

    if ((s[idx] == 'D' || s[idx] == '?') && row < 6 && !mark[row + 1][col]) {
        if (!(!isValid(row + 2, col) && isValid(row + 1, col - 1) && isValid(row + 1, col + 1))) {
            backtrack(row + 1, col, idx + 1);
        }
    }

    if ((s[idx] == 'L' || s[idx] == '?') && col && !mark[row][col - 1]) {
        if (!(!isValid(row, col - 2) && isValid(row - 1, col - 1) && isValid(row + 1, col - 1))) {
            backtrack(row, col - 1, idx + 1);
        }
    }

    mark[row][col] = false;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    memset(mark, false, sizeof(mark));

    cin >> s;

    mark[0][0] = true;
    backtrack(0, 0, 0);

    cout << res << endl;
    return 0;
}
