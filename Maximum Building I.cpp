#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(ll i = x; i <= y; i++)
typedef long long ll;

const ll N = 1002, M = 1002;
int a[N][M], m, n;

ll process(ll a[], ll n){

    stack<ll> s;
 
    ll max_area = 0, stp = 0, area_with_top = 0; 
 
    ll i = 0;
    while (i < n)
    {
        if (s.empty() || a[s.top()] <= a[i])
            s.push(i++);
        else
        {
            stp = s.top();
            s.pop();

            if (s.empty()){
                area_with_top = a[stp] * i;
            }
            else area_with_top = a[stp] * (i - s.top() - 1);

            max_area = max(max_area,area_with_top);
        }
    }

    while (s.empty() == false){
        stp = s.top();
        s.pop();
        if (s.empty()){
                area_with_top = a[stp] * i;
        }
        else area_with_top = a[stp] * (i - s.top() - 1);
            
        max_area = max(max_area,area_with_top);
    }
 
    return max_area;
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
   
    FOR(i,0,n-1){
    	FOR(j,0,m-1){
    		char x;
  			cin >> x;
  			if (x == '.') a[i][j] = 1;
			else a[i][j] = 0;
    	}
    }
    ll a2[M], max_area = 0;

    FOR(j,0,m-1) a2[j] = 0;

    FOR(i,0,n-1){
    	FOR(j,0,m-1){
    		if (a[i][j] == 0) a2[j] = 0;
    		else a2[j]++;
    	}
    	max_area = max(max_area, process(a2,m));	
    }
    cout << max_area;
    return 0;
}
