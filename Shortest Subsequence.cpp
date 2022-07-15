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

const ll N = 1e5 + 5;

int n, cnt;
char ch[4] = {'A', 'C', 'G', 'T'};;
bool check[4];
map<char, int> mymap;
vll res;

void init(){
	mymap['A'] = 0;
	mymap['C'] = 1;
	mymap['G'] = 2;
	mymap['T'] = 3;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    
    init();
    str s;
    cin >> s;
    n = s.size();

    FOR(i,0,n - 1){
    	int c = mymap[s[i]];
        if(!check[c]){
            check[c] = 1;
            cnt++;
            if(cnt == 4){
            	memset(check, 0, sizeof(check));
                
                res.pb(i);
                cnt = 0;
            }
        }
    }

    for(int i : res)
        cout << s[i];

    for(int i = 0; i < 4; i++){
        if(!check[i]){
            cout << ch[i];
            el;
            return 0;
        }
    }
    return 0;
}
