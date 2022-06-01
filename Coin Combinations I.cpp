#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vi vector<int>
const ll MOD = 1e9 + 7;

ll dp[1000001]; 

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    int n, x;
    cin >> n >> x;    
    vi coins(n);    
    for (int i = 0; i < n; i++)       
        cin >> coins[i];      
    dp[0] = 1;    
    for (int weight = 0; weight <= x; weight++) {        
        for (int i = 1; i <= n; i++) {            
            if(weight - coins[i - 1] >= 0) {                
                dp[weight] += dp[weight - coins[i - 1]];                
                dp[weight] %= MOD;            
            }        
        }    
    }    
    cout << dp[x] << '\n';
}