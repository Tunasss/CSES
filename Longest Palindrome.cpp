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

string longestPalindrome(string mainString)
{
  	int n = mainString.size();
  	if(n == 0)
      return "";
  	n = 2 * n + 1;
	int LPS[n];
	LPS[0] = 0;
	LPS[1] = 1;
	int centerIndex = 1;
	int rightIndex = 2;
	int right = 0, left;
	int maxPalLength = 0, maxCenterIndex = 0;
	int start = -1, end = -1, diff = -1;

	for (right = 2; right < n; right++) {
	    left  = 2*centerIndex - right;
	    LPS[right] = 0;
	    diff = rightIndex - right;

	    if(diff > 0)
	        LPS[right] = min(LPS[left], diff);
	    while ( ((right + LPS[right]) < n && (right - LPS[right]) > 0) && ( ((right + LPS[right] + 1) % 2 == 0) || (mainString[(right + LPS[right] + 1)/2] == mainString[(right - LPS[right] - 1)/2] ))){
	        LPS[right]++;
	    }

	    if(LPS[right] > maxPalLength) {
	        maxPalLength = LPS[right];
	        maxCenterIndex = right;
	    }

	    if (right + LPS[right] > rightIndex) {
	        centerIndex = right;
	        rightIndex = right + LPS[right];
	    }
	}

	start = (maxCenterIndex - maxPalLength)/2;
	end = start + maxPalLength - 1;
	string palindrome;

	for(int i=start; i<=end; i++)
	    palindrome += mainString[i];
	return palindrome;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    str mainString, palindrome;
  	cin >> mainString;
  	palindrome = longestPalindrome(mainString);
  	cout << palindrome << endl;
    
    return 0;
}