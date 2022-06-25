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


const ll N = 2 * 1e5 + 5;
ll a[N],n;

ll process(ll a[], ll n){

    stack<ll> s;
 
    ll max_area = 0, tp = 0, area_with_top = 0; 
 
    ll i = 0;
    while (i < n)
    {
        if (s.empty() || a[s.top()] <= a[i])
            s.push(i++);
        else
        {
            tp = s.top();
            s.pop();

            if (s.empty()){
                area_with_top = a[tp] * i;
            }
            else area_with_top = a[tp] * (i - s.top() - 1);

            max_area = max(max_area,area_with_top);
        }
    }

    while (s.empty() == false){
        tp = s.top();
        s.pop();
        if (s.empty()){
                area_with_top = a[tp] * i;
        }
        else area_with_top = a[tp] * (i - s.top() - 1);
            
        max_area = max(max_area,area_with_top);
    }
 
    return max_area;
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll n;
    cin >> n;
    FOR(i,0,n-1) cin >> a[i];
    cout << process(a,n);
    
    return 0;
}
