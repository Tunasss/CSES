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
#define pb push_bacid
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

const ll T = 4e6 + 5;

int tree[T][4], n;

ll maxbomaytuche(ll a, ll b, ll c){
	return max(max(a,b),c);
}

void update(int id, int x) {
    id += n;
    FOR(i,0,3) tree[id][i] = x;

    id >>= 1;

    while(id > 0) {
        tree[id][0] = max(0LL, maxbomaytuche(tree[2 * id][0], tree[2 * id + 1][0], tree[2 * id][2] + tree[2 * id + 1][1])); //max
        tree[id][1] = maxbomaytuche(tree[2 * id][1], tree[2 * id][3] + tree[2 * id + 1][1], 0LL); //pre
        tree[id][2] = maxbomaytuche(tree[2 * id][2] + tree[2 * id +1][3], tree[2 * id+1][2], 0LL); //suff
        tree[id][3] = tree[2 * id][3] + tree[2 * id + 1][3]; //total
        id >>= 1;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    
    int temp,q; 
    cin >> temp >> q;
    n = pow(2,ceil(log2(temp)));
    FOR(i,0,temp - 1) {
        int x; 
        cin >> x;
        update(i,x);
    }
    while(q--) {
        int id,x; 
        cin >> id >> x;
        update(id - 1,x);
        cout << tree[1][0];
        el;
    }

    return 0;
}