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
	vll a(n);

	FOR(i,0,n-1) cin >> a[i];

	map<int,ii> sum;

	FOR(i,0,n-1){
		FOR(j,i+1,n-1){
			int diff = x - a[i] - a[j];
			if(sum.count(diff)){
				cout << i + 1 << " " << j + 1 << " " <<  sum[diff].st + 1 << " " << sum[diff].nd + 1;
				return 0;
			}
		}
		FOS(j,i-1,0){
			sum[a[i] + a[j]] = {i,j};
		}
	}
	cout << "IMPOSSIBLE";
}