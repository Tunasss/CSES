#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const long long B = 1e9 + 9, A = 9973;

ll p[N], h[N];
ll n;
string s;

void calc_h() {
	h[0] = 1;
	for (ll i = 0; i < n; i++) {
		h[i + 1] = ((h[i] * A) % B + s[i]) % B;
	}
}

ll get_h(ll a, ll b) {
	return (h[b + 1] - (h[a] * p[b - a + 1]) % B + B) % B;
}

void calc_p() {
	p[0] = 1;
	for (ll i = 1; i < N; i++) {
		p[i] = (p[i - 1] * A) % B;
	}
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll t;
    cin >> t;
    calc_p();
    while(t--){
    	cin >> s;
		n = s.size();
		calc_h();

		ll res = 1;
		for (ll i = 0; i < n / 2; i++) {
			ll j = i, l = n - i - 1, r = n - i - 1;

			for (; j < n / 2; ++j,
			 --l) {
				if (get_hash(i, j) == get_hash(l, r)) {
					res += 2;
					if (n % 2 == 0 && j == n / 2 - 1) {
						--res;
					}
					break;
				}
			}
			i = j;
		}
		cout << res << "\n";
    }
    
    return 0;
}
