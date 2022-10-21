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

struct node
{
    map<int, node*> tree;
    node* link;
    int cnt;

    node()
    {
        link = nullptr;
        cnt = 0;
    }
};

node* newNode()
{
    node* n = new node;
    return n;
}

void insert(node* root, string s)
{
    node* v = root;
    for (int x : s)
    {
        if (!v -> tree[x])
            v -> tree[x] = newNode();
        v = v -> tree[x];
    }
}

void build(node* root)
{
    queue<node*> que;
    que.push(root);

    while (!que.empty())
    {
        node* v = que.front();
        que.pop();

        for (int i = 'a'; i <= 'z'; i++)
            if (v->tree.count(i) > 0)
            {
                que.push(v -> tree[i]);
                v -> tree[i] -> link = root;
                node * p = v -> link;
                while (p)
                {
                    if (p->tree.count(i) > 0)
                    {
                        v -> tree[i] -> link = p -> tree[i];
                        break;
                    }

                    if (!p -> link)
                        break;
                    p = p -> link;
                }
            }
    }
}

vector<pair<node*, int> > vv;

void dfs(node *u, int h)
{
    vv.push_back({u, h});

    for (int i = 'a'; i <= 'z'; ++i)
    {
        if (u->tree.count(i) > 0)
        {
            dfs(u->tree[i], h + 1);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    str s; cin >> s;
    int n; cin >> n;

    node* root = newNode();

    vector<string> t(n);
    for (auto &x : t)
    {
        cin >> x;
        insert(root, x);
    }

    build(root);

    node* v = root;
    for (int x : s)
    {
        while (1)
        {
            if (v->tree.count(x) > 0)
            {
                v = v -> tree[x];
                break;
            }

            if (!v -> link)
                break;
            v = v -> link;
        }
        v -> cnt++;
    }

    dfs(root, 1);

    sort(vv.begin(), vv.end(), [&](pair<node*, int> L, pair<node*, int> R) {
        return L.nd > R.nd;
    });

    for (auto current : vv)
        if (current.st -> link)
            current.st -> link -> cnt += current.st -> cnt;

    for (auto x : t)
    {
        node* v = root;
        for (int c : x)
            v = v -> tree[c];
        cout << v -> cnt << "\n";
    }
    return 0;
}