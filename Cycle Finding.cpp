#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
/*
       _,    _   _    ,_
  .o888P     Y8o8Y     Y888o.
 d88888      88888      88888b
d888888b_  _d88888b_  _d888888b
8888888888888888888888888888888
8888888888888888888888888888888
YJGS8P"Y888P"Y888P"Y888P"Y8888P
 Y888   '8'   Y8P   '8'   888Y
  '8o          V          o8'
*/
//Tunass

//I. Định nghĩa các kiểu dữ liệu
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;

//II. Định nghĩa các từ hay dùng (snippet)
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
#define fto(i,x,y) for(ll i = x; i <= y; i++)

//III. Định nghĩa các MAX của kiểu dữ liệu
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;

//IV. Định nghĩa hàm Debug
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;

struct E {
	int a, b;
	ll c;
	E(int a, int b, ll c) : a(a), b(b), c(c) {}
};
const ll oo = 1e15;
int n, m;
vector<E> e;
ll w[2501], _w[2501];
bool ok = 0;
int bp = -1;
int p[2501];
int c[2501];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		w[i] = oo;
	for (int i = 1; i <= m; ++i) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		e.pb(E(a, b, c));
	}
	// Bellman-ford
	for (int i = 1; i < n; ++i)
		for (auto j : e)
			w[j.b] = min(w[j.b], w[j.a] + j.c);
	for (int i = 1; i <= n; ++i)
		_w[i] = w[i];
	for (int i = 1; i <= (n << 2); ++i)
		for (auto j : e) {
			ll s = _w[j.b];
			_w[j.b] = min(_w[j.b], _w[j.a] + j.c);
			if (s != _w[j.b])
				p[j.b] = j.a;
		}
	for (int i = 1; i <= n; ++i)
		if (_w[i] != w[i])
			ok = 1;
	if (ok) {
		cout << "YES\n";
		int no = -1;
		for (int i = 1; i <= n; ++i)
			if (_w[i] != w[i])
				no = i;
		for (int i = 1; i <= n; ++i)
			no = p[no];
		vi cy;
		while (1) {
			cy.pb(no);
			++c[no];
			if (c[no] == 2)
				break;
			no = p[no];
		}
		reverse(cy.begin(), cy.end());
		for (int i : cy)
			cout << i << ' ';
	}
	else cout << "NO";
	return 0;
}