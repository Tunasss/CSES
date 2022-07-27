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

struct node{
    node* tree[128];
    node* link;
    bool end;
 
    bool calc;
    bool match;
};
 
node* newNode(){
    node* n = new node;
    for (int i = 0; i < 128; i++)
        n -> tree[i] = 0;
    n -> end = n -> calc = n -> match = false;
    n -> link = nullptr;
    return n;
}
 
void build(node* root){
    queue<node*> que;
    que.push(root);
 
    while (!que.empty()){
        node* v = que.front();
        que.pop();
        for (int i = 'a'; i <= 'z'; i++){
            if (v -> tree[i]){
                v -> tree[i] -> link = root;
                node* p = v -> link;
 
                while (p){
                    if (p -> tree[i]){
                        v -> tree[i] -> link = p -> tree[i];
                        break;
                    }
 
                    if (!p -> link)
                        break;
 
                    p = p -> link;
                }
                que.push(v -> tree[i]);
            }
        }
    }
}
 
void insert(node* root, string s){
    node* v = root;
    for (int x: s){
        if (!v -> tree[x])
            v -> tree[x] = newNode();
        v = v -> tree[x];
    }
    v -> end = true;
}

void mark(node* v){
    if (!v) return;
 
    if (v -> calc) return;
 
    v -> match = true;
    v -> calc = true;
    mark(v -> link);
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    string s; cin >> s;
 
    int n; cin >> n;
    vector<string> t(n);
    node* root = newNode();
 
    for (int i = 0; i < n; i++){
        cin >> t[i];
        insert(root, t[i]);
    }
 
    build(root);
 
    node* v = root;
    for (int x: s){
        while (1){
            if (v -> tree[x]){
                v = v -> tree[x];
                break;
            }
 
            if (!v -> link)
                break;
 
            v = v -> link;
        }
        mark(v);
    }
 
    for (auto x: t){
        v = root;
        for (int c: x)
            v = v -> tree[c];
        
        if (v -> match)
            cout << "YES";
        else cout << "NO";
        el;
    }
    return 0;
}
