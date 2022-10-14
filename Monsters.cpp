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

//#define int long long
const ll N = 1e3 + 5;
int n, m, x, y;

int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
char go[] = {'U', 'D', 'R', ''};

char A[N][N];
int nex[N][N];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    queue<ii> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
            if (A[i][j] == 'M') {
                q.push({i, j});

            } else if (A[i][j] == 'A') {
                x = i;
                y = j;
            }
        }
    }

    q.push({x, y});
    nex[x][y] = -1;

    while (!q.empty()) {
        ii t = q.front();
        q.pop();

        int x, y;
        x = t.first;
        y = t.second;
        if (A[x][y] == 'A' && (x == 0 || x == n - 1 || y == 0 || y == m - 1))
        {
            cout << "YES"; el;
            string ans;
            int d = nex[x][y];
            while (d != -1) {
                ans += go[d];
                x -= dx[d];
                y -= dy[d];
                d = nex[x][y];

            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << endl;
            cout << ans;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int xx = t.first + dx[i];
            int yy = t.second + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && A[xx][yy] == '.') {
                A[xx][yy] = A[t.first][t.second];
                if (A[xx][yy] == 'A') {
                    nex[xx][yy] = i;
                }
                q.push({xx, yy});
            }

        }

    }
    cout << "NO"; el;
    return 0;
}
