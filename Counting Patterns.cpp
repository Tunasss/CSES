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

map<string, int> ans;
struct TrieNode{
    struct TrieNode *child[26] = {NULL};;
    int End = 0;
    int count = 0;
};

struct TrieNode *NewNode(void)
{
    struct TrieNode *pNode = new TrieNode;
 
    pNode->End = false;
 
    for (int i = 0; i < 26; i++)
        pNode->child[i] = NULL;
 
    return pNode;
}

void add(TrieNode *root, string s, bool&check){
    TrieNode *Insert = root;
    for(int i = 0; i < s.size(); i++){
        int pos = s[i] - 'a';
        if(!Insert -> child[pos]){
            Insert -> child[pos] = new TrieNode();
            Insert -> count++;
        }
        if(Insert -> count > 1) check = 0;
        Insert = Insert -> child[pos];
    }
    Insert -> End = 1;
}

void xuli(TrieNode *root, string t, int j){
    string s;
    TrieNode *kt = root, *save = NULL;
    for(int i = j; i < t.size(); i++){
        s += t[i];
        int pos = t[i] - 'a';
        if(!kt -> child[pos]) return;
        kt = kt -> child[pos];
        if(kt -> End) ans[s]++;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    int n; string s; bool check = 1;
    cin >> s >> n;
    vector<string> a(n); TrieNode *root = new TrieNode();
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(s.find(a[i][a[i].size() - 1]) != string::npos 
		&& s.size() >= a[i].size())
            add(root, a[i], check);
    }
    if(check){
        int d = s.size();
        for(int i = 0; i < n; i++){
            cout << d << endl;
            d--;
        }
        return 0;
    }
	for(int i = 0; i < s.size(); i++) xuli(root, s, i);
    for(int i = 0; i < n; i++)
        cout << ans[a[i]] << endl;
    
    return 0;
}

