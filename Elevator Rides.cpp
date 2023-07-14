#include <bits/stdc++.h>

using namespace std;

int a[100005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, k;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++) 
       cin >> a[i];

    int j = 0;
    long long sum = 0, res = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        while(sum > k && j < n) {
            sum -= a[j];
            j++;
        }
        res += (i - j + 1);
        cout << res << ' ' << j << '\n';
    };
    cout << res;
    return 0;
}
