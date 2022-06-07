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

const ll A = 9973, B = 1e9 + 1, N = 1111111;
ll p[N], h[N];
string a, b;

ll Hash(int x,int y) {
    if(x == 0) return h[y];
    return (h[y] - h[x - 1] * p[y - x + 1] + B * B) % B;
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> a >> b;
    h[0] = a[0];
    p[0] = 1;
    for (int i = 1; i < a.size(); i++){
        p[i] = (p[i - 1] * A) % B;
        h[i] = (h[i - 1] * A + a[i]) % B;
    }
    
    ll hash_value = b[0];
    ll res = 0;

    for(int i = 1; i < b.size(); i++)
        hash_value = (hash_value  * A + b[i]) % B;
    for(int i = 0; i < a.size() - b.size() + 1; i++)
        if(hash_value == Hash(i, i + b.size() - 1)) res++;
    cout << res;
} 