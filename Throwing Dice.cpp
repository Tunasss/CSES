#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define el cout << '\n';

const ll MOD = 1e9 + 7;
const ll N = 111;
 
ll n;

struct Matrix {

int rowSize = N - 1;
int columnSize = N - 1;
int m[N][N] = {};

Matrix(){
    for (int i = 1; i <= rowSize; ++i) {
        for (int j = 1; j <= columnSize; ++j) {
            m[i][j] = 0;
        }
    }
}

Matrix operator * (Matrix b) {
    Matrix C;
    for (int i = 1; i <= rowSize; ++i) {
        for (int j = 1; j <= b.columnSize; ++j) {
            C.m[i][j] = 0;
            for (int k = 1; k <= columnSize; ++k) {
                C.m[i][j] = (C.m[i][j] + 1LL * m[i][k] * b.m[k][j] % MOD) % MOD;
            }
        }
    }
    C.rowSize = rowSize;
    C.columnSize = b.columnSize;
    return C;
}

Matrix identity(int n){
    Matrix C;
    C.rowSize = n;
    C.columnSize = n;
    for (int i = 1; i <= n; i++) {
        C.m[i][i] = 1;
    }
    return C;
}

};
 
Matrix Pow(Matrix a, ll n) {
    if (n == 0) return a.identity(a.rowSize);
    if (n == 1) return a;
    if (n & 1) return Pow(a,n - 1) * a;
    Matrix tmp = Pow(a, n / 2);
    return tmp * tmp;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n;
    Matrix base, D;

    D.rowSize = 6;
    D.columnSize = 6;

    for (int i = 1; i <= 6; i++) {
        D.m[i][i + 1] = 1;
    	D.m[6][i] = 1;
    }

    Matrix ans = Pow(D, n);
    cout<< ans.m[6][6];
    el;
    return 0;
}
