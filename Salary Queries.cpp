#include <bits/stdc++.h>
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <ll,ll> ii;
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

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

const int N = 2e5 + 5;
	
int n, q;
ll a[N];

Tree<ii> tre;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

	cin >> n >> q;

	FOR(i,1,n){
		cin >> a[i];
		tre.insert({a[i], i});
	}

	FOR(i,1,q) {
		char c; 
		cin >> c;
		if (c == '!') {
			int x,y; 

			cin >> x >> y;
			tre.erase({a[x],x});

			a[x] = y;
			tre.insert({a[x],x});
		} 
		else {
			int x,y;
			cin >> x >> y;
			cout << tre.order_of_key({y,MOD}) - tre.order_of_key({x - 1,MOD}) << '\n';
		}
	}

	return 0;
}