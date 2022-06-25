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

const ll N = 2e5 + 5;
ll a[N], n;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n;
	vector<pair<ii,ll> > v(n);

	for (ll i = 0; i < n; i++) {
		cin >> v[i].st.st >> v[i].st.nd;
		v[i].nd = i;
	}
	sort(v.begin(), v.end());
    
	ll rooms = 0, last_room = 0;

	priority_queue<ii> pq;

	for (ll i = 0; i < n; i++) {
		if (pq.empty()) {
			last_room++;

			pq.push({-v[i].st.second, last_room});
			a[v[i].nd] = last_room;
		}
		else {
			
			ii minimum = pq.top();
			if (-minimum.st < v[i].st.st) {
				pq.pop();
				pq.push({-v[i].st.nd, minimum.second});
				a[v[i].nd] = minimum.nd;
			}

			else {
				last_room++;
				pq.push({-v[i].st.second, last_room});
				a[v[i].nd] = last_room;
			}
		}

		rooms = max(rooms, (ll)pq.size());
	}

	cout << rooms << "\n";
	for (ll i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

    return 0;
}
