#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200;

int f[MAXN][MAXN] = {0};
int res = 0;
int n;

void fill(int a, int b, int c) {
    for(int i = a; i < b; i++) {
        for(int j = 0; j < c; j++) {
            if (!f[i][j]) {
                res++;
            }
            f[i][j] = 1;
        }
    }
}

void solve() {
    while (n--) {
        int i, j, k;
        cin >> i >> j >> k;
        fill(i, j, k);
    }
    cout << res;
}

int main() {
    cin >> n;
    solve();
}