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
#define FOR(i,x,y) for(ll i = x; i <= y; i++)
#define FOS(i,x,y) for(ll i = x; i >= y; i--)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll N = 1e6 + 5;
ll k, dem = 0;
ll trie[N][26] = {}, dp[N] = {};
bool check[N];

void insert(str s){
	ll node = 0;
	for (ll i = 0; i < s.size(); i++){
		if (!trie[node][s[i] - 'a']) trie[node][s[i] - 'a'] = ++dem;
		node = trie[node][s[i] - 'a'];
	}	
	check[node] = 1;
}

str s;

ll search(ll x){
	ll node = 0, res = 0;
	for (ll i = x; i < s.size(); i++){
		if (!trie[node][s[i] - 'a']) return res;
		
		node = trie[node][s[i] - 'a'];

		if (check[node]) {
			(res += dp[i + 1]) %= MOD;
		}
	}
	return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

	cin >> s;
	cin >> k;
    while(k--){
    	str x;
    	cin >> x;
    	insert(x);
    }
    dp[s.size()] = 1;
    for (ll i = s.size() - 1; i >= 0; i--){
    	dp[i] = search(i);
    }
    cout << dp[0];

    return 0;
}