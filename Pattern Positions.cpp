#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;
#define file "TEST"
#define st first
#define nd second
#define pb push_back
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

/*
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }
*/

//#define int long long
const ll N = 2e5 + 5;
 
struct node{
    node* tree[128] = {};
    node* link = nullptr;
 
    int match = -1;
};
 
node* newNode(){
    return new node;
}
 
void insert(node* root, string s){
    node* v = root;
    for (int x: s){
        if (!v -> tree[x])
            v -> tree[x] = newNode();
        v = v -> tree[x];
    }
}
 
void build(node* root){
    queue<node*> que;
    que.push(root);
 
    while (!que.empty()){
        node* v = que.front();
        que.pop();
 
        for (int i = 'a'; i <= 'z'; i++){
            if (v -> tree[i]){
                que.push(v -> tree[i]);
                v -> tree[i] -> link = root;
                node* p = v -> link;
                while (p){
                    if (p -> tree[i]){
                        v -> tree[i] -> link = p -> tree[i];
                        break;
                    }
 
                    if (!p -> link) break;
                    p = p -> link;
                }
            }
        }
    }
}
 
void mark(node* x, int i){
    if (!x) return;
    if (x -> match != -1) return;
 
    x -> match = i;
    mark(x -> link, i);
}
 

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    str s; cin >> s;
    int n; cin >> n;
    vector<str> t(n);
 
    node* root = newNode();
 
    for (auto &x: t){
        cin >> x;
        insert(root, x);
    }
 
    build(root);
 
    node* v = root;
    for (int i = 0, c = s[0]; i < s.size(); i++, c = s[i]){
        while (1){
            if (v -> tree[c]){
                v = v -> tree[c];
                break;
            }
 
            if (!v -> link) break;
            v = v -> link;
        }
        mark(v, i);
    }
 
    for (auto x: t){
        node* v = root;
        for (int c: x)
            v = v -> tree[c];
        
        if (v -> match == -1) cout << "-1\n";
        else cout << v -> match - x.size() + 1 + 1 << "\n";
    }
    return 0;
}