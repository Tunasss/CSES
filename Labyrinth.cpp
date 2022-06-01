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

#define ar array

const int sz = 1e3+2;
const int di[4] = {1,0,-1,0}, dj[4]={0,1,0,-1};
const char dc[4] = {'D','R','U','L'} ;
int n,m,si,sj,ti,tj,d[sz][sz];
str s[sz], p[sz];

bool e(int i,int j){
    return (i < n && i >= 0 && j < m && j >= 0 && s[i][j] == '.') ;
}

//V. Chương trình chính
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    cin >> n >> m ;
    for(int i = 0; i < n; i++)
        cin >> s[i] ; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == 'A')
                si = i,sj = j, s[i][j] = '.';
            if(s[i][j] == 'B')
                ti = i,tj = j, s[i][j] = '.';
        }
    p[i] = string(m,0);
    }
    queue<ar<int,2>>qu ;
    qu.push({si,sj}) ;
    while(!qu.empty()){
    ar<int,2>u = qu.front();
    qu.pop() ;
    for(int k = 0; k < 4; k++){
        int ni = u[0] + di[k], nj = u[1] + dj[k];
        if(!e(ni,nj))
            continue;
        qu.push({ni,nj});
        s[ni][nj] = '#';
        d[ni][nj] = k;
        p[ni][nj] = dc[k];
        }
    }
    if(p[ti][tj]){
        str t;
        cout << "YES"<< endl ;
        while(si ^ ti || sj ^ tj){
            t += p[ti][tj] ;
            int dd = d[ti][tj] ^ 2;
            ti += di[dd];
            tj += dj[dd];
        }
        reverse(t.begin(),t.end());
        cout << t.size() <<"\n";
        cout << t;
    }
    else cout << "NO";

    cerr << "\nTime: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
    return 0;
}