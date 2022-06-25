#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <int,int> ii;
#define st first
#define nd second
#define vll vector<ll>
#define FOR(i,x,y) for(ll i = x; i <= y; i++)
#define FOS(i,x,y) for(ll i = x; i >= y; i--)

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
	ll n,x; 
	cin >> n >> x;
	vector<ii> arr;

	FOR(i,1,n){
		ll a; 
		cin >> a;

		ii p; 
		p.first = a; 
		p.second = i;

		arr.push_back(p);
	}

	sort(begin(arr), end(arr));

	for(ll i = 0; i < n; i++){
		ll l, r; 
		l = 0; r = n - 1;
		while(l != r){
			ll target; 
			target = x - arr.at(i).first;
			if(l != i && r != i && arr.at(l).first + arr.at(r).first == target){
				cout << arr.at(i).second << " " << arr.at(l).second
					 << " " << arr.at(r).second << endl;
				return 0;
			}
			if(arr.at(l).first + arr.at(r).first < target){
				l++;
			}
			else{
				r--;
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
}