#include <bits/stdc++.h>
#include <unordered_map>
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
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll N = 1005;

bool a[N][N];
int dp[N][N];
int n, q;

void init(){
	dp[0][0] = dp[1][0] = dp[0][1] = 0;
	FOR(i,1,n){
		FOR(j,1,n){
			dp[i][j] = a[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
		}
	}
}

int query(int x1, int y1, int x2, int y2){
	return dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(file".INP","r",stdin);
	//freopen(file".OUT","w",stdout);

	cin >> n >> q;

	FOR(i,1,n){
		FOR(j,1,n){
			char c; cin >> c;
			if (c == '*'){
				a[i][j] = 1;
			}
			else a[i][j] = 0;
		}
	}

	init();

	while (q--)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << query(x1, y1, x2, y2);
		el;
	}
	return 0;
}