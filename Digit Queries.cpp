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

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    ll t;
    cin >> t;
    while(t--){
    	ll n;
	    ll pow10 = 1, num = 0; 
	    cin >> n;
		for (ll i = 1; i < 18; i++) {
		    pow10 *= 10;
		    ll knt = ( pow10 - (pow10 / 10) ) * i;
		    if (n > knt) {
			    n -= knt;
			    num = pow10 - 1;
		    } 
		    else {
		      	num += (n + i - 1) / i;
		      	str ans = to_string(num);
		      	ll index = (n % i == 0 ? i - 1 : n % i - 1);
		      	cout << ans[index] << '\n';
		      	break;
		    }
		}
    }
    return 0;
}
