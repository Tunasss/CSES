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

const int N = 2e5 + 5;
const int T = N << 2;

int n, q, a[N];
ll tree[T];

void build(int id = 1, int L = 1, int R = n) {
	if (L == R) {
		tree[id] = a[L];
		return;
	}

	int M = (L + R) / 2;

	build(2 * id, L, M);
	build(2 * id + 1, M + 1, R);

	tree[id] = max(tree[2 * id], tree[2 * id + 1]);
}

void update(int u, int id = 1, int L = 1, int R = n) {
	if (L == R) {
		tree[id] -= u;
		cout << L << ' ';
		return;
	}

	int M = (L + R) / 2;

	if (tree[id << 1] >= u) update(u, 2 * id, L, M);
	else update(u, 2 * id + 1, M + 1, R);

	tree[id] = max(tree[2 * id], tree[2 * id + 1]);
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    
    cin >> n >> q;

    FOR(i,1,n) cin >> a[i];

    build();

    while(q--) {
    	ll x;
    	cin >> x;

    	if(x > tree[1]){
    		cout << 0 << ' ';
    	}

    	else {
    		update(x);
    	}
    }
    return 0;
}
