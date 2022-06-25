#include <bits/stdc++.h>
 
using namespace std;
 
int m, n;
vector<vector<int>> graph;
vector<bool> danhdau;
 
void DFS(int v){
    if(danhdau[v]) return;
    danhdau[v] = true;
    for (auto u: graph[v]){
        DFS(u);
    }
}
 
int main() {
    cin >> m >> n;
    graph.resize(m + 1);
    danhdau.assign(m + 1, 0);
    for (int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int pre_i = 1;
    int dem = 0;
    queue<pair<int, int>> myque;
    DFS(1);
    for (int i = 1; i <= m; i++){
        if (danhdau[i] == false){
            DFS(i);
            dem++;
            myque.push({pre_i, i});
        }
    }
    cout << dem << endl;
    while(!myque.empty()){
        pair<int, int> topp = myque.front();
        myque.pop();
        cout << topp.first << " " << topp.second << endl;
    }
    return 0;
}
