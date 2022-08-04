#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
 
const ll N = 2e5 + 10;
 
struct range{
	int l, r, id;
	bool operator < (const range &b) const{
		if (l == b.l) return r > b.r;
		return l < b.l;
	}
};
 
signed main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
 
	int n; cin >> n;
	range range[N];
	bool maxR[N], minR[N];
 
	for (int i = 0; i < n; ++i){
		cin >> range[i].l >> range[i].r;
		range[i].id = i;
 	}
 
 	sort(range, range + n);
 	int maxEnd = 0;
 
 	for (int i = 0; i < n; ++i){
 		if (range[i].r <= maxEnd) maxR[range[i].id] = 1;
 		maxEnd = max(maxEnd, range[i].r);
 	}
 
 	int minEnd = 1e9 + 1;
 
 	for (int i = n - 1; i >= 0; --i){
 		if (range[i].r >= minEnd) minR[range[i].id] = 1;
 		minEnd = min(minEnd, range[i].r);
 	}
 
 	for (int i = 0; i < n; ++i) cout << minR[i] << ' ';
 	cout << '\n';
 
 	for (int i = 0; i < n; ++i) cout << maxR[i] << ' ';
 	cout << '\n';
 
	return 0;
}