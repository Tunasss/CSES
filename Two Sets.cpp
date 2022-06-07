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

//IV. Định nghĩa hàm sinh số Random từ L đến R
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

//V. Chương trình chính
int main() {
    int n;
    cin >> n;
    ll sum = 1ll * n * (n + 1) / 2;
    if (sum % 2) cout << "NO\n";
    else {
        sum /= 2;
        vector<int> v;
        ll temp = 0;
        ll diff = 0;
        int i = n;
        while (true) {
            v.push_back(i);
            temp += i--;
            diff = sum - temp;
            if (diff == 0) break; 
            if (diff <= i) {
                v.push_back(diff);
                break;
            }
        }
        cout << "YES\n";
        cout << v.size() << endl;

        for (int j = 0; j < v.size(); j++) {
            cout << v[j];
            if (j < v.size() - 1) cout << " ";
        }
        cout << endl;


        cout << n - v.size() << endl;
        for (ll j = i; j > 0; j--) { //starting by i, the element we jumped over
            if (j == diff) continue; //we skip the last element we inserted in the first set
            cout << j;
            if ((diff != 1 && j > 1) || (diff == 1 && j > 2)) cout << " "; //spacing problem
        }
        cout << endl;
    }
}
