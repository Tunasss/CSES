#include <bits/stdc++.h>
 
using namespace std;
 
int m, n;
vector<vector<int>> arr;
 
int const moves = 4;
int dex_i[moves] = {0 , 1 , -1,  0};
int dex_j[moves] = {1 , 0 ,  0, -1};
 
bool DFS(int i, int j){
    if (i == -1 || j == -1) return false;
    if (i == m || j == n) return false;
    if (arr[i][j] == 0) return false;
    arr[i][j] = 0;
    bool tong = false;
    for(int x = 0; x < moves; x++){
        tong = tong | DFS(i + dex_i[x],j + dex_j[x]);
    }
    return tong;
}
 
 
int main() {
    cin >> m >> n;
    arr.assign(m, vector<int>(n,0));
    for (int i = 0; i < m; i++){
        string s;
        cin >> s;
        for (int j = 0; j < n; j++){
            if(s[j] == '.') arr[i][j] = 1;
        }
    }
    int dem = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (arr[i][j] == 1)
            {
                DFS(i,j);
                dem++;
            }
        }
    }
    cout << dem;
    return 0;
}