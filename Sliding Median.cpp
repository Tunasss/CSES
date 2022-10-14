#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <ll, ll> ii;
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
#define el cout << endl;
#define all(v) (v).begin(), (v).end()
#define FOR(i,x,y) for(ll i = x; i <= y; i++)
#define FOS(i,x,y) for(ll i = x; i >= y; i--)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

int main() {
    int n, k;
    cin >> n >> k;
    set<pair<int, int>> leftSet;
    set<pair<int, int>> rightSet;
    vector<int> values(n);

    for (int i = 0; i < n; i++)
        cin >> values[i];

    if (k == 1)
    {
        for (int i = 0; i < n; i++)
            cout << values[i] << " ";
        return 0;
    }

    if (k == 2)
    {
        for (int i = 1; i < n; i++)
            cout << min(values[i - 1], values[i]) << " ";
        return 0;
    }

    vector<pair<int, int>> st;
    for (int i = 0; i < k; i++)
        st.push_back({values[i], i});

    sort(st.begin(), st.end());

    for (int i = 0; i < k / 2 + (k % 2); i++)
        leftSet.insert(st[i]);

    for (int i = k / 2 + (k % 2); i < k; i++)
        rightSet.insert(st[i]);

    auto t = leftSet.rbegin();
    cout << t -> first << " ";

    for (int j = 1; j < n - k + 1; j++)
    {
        if (leftSet.count({values[j - 1], j - 1}))
            leftSet.erase({values[j - 1], j - 1});
        else
            rightSet.erase({values[j - 1], j - 1});
        if (*(leftSet.rbegin()) < make_pair(values[k - 1 + j], k - 1 + j))
            rightSet.insert({values[k - 1 + j], k - 1 + j});
        else
            leftSet.insert({values[k - 1 + j], k - 1 + j});
        while (leftSet.size() < k / 2 + (k % 2))
        {
            pair<int, int> z = (*rightSet.begin());
            leftSet.insert(z);
            rightSet.erase(z);
        }
        while (leftSet.size() > k / 2 + (k % 2))
        {
            pair<int, int> z = (*leftSet.rbegin());
            leftSet.erase(z);
            rightSet.insert(z);
        }
        cout << leftSet.rbegin() -> first << " ";
    }
}