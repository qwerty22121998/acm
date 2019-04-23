#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int n, m, hh;
vector<int> a, b;
int h[MAXN][MAXN] = {0};
int g[MAXN][MAXN] = {0};
int f[MAXN][MAXN][MAXN] = {0};
void solve() {
    for(int z = 0; z < a.size(); z++) {
        for(int y = 0;y < a[z]; y++) {
            for(int x = 0; x < n; x++) {
                f[x][y][z]++;
            }
        }
    }
    for(int x = 0; x < b.size(); x++) {
        for(int y = 0; y < b[x]; y++) {
            for(int z = 0; z < m; z++) {
                f[x][y][z]++;
            }
        }
    }

    for(int x = 0; x < n; x++) {
        for(int z = 0; z < m; z++) {
            if (h[x][z] == 1) {
                for(int y = 0; y < hh; y++) {
                    f[x][y][z]++;
                }
            }
        }
    }

    for(int x = 0; x < n; x++) {
        for(int y = 0; y < hh; y++) {
            for (int z = 0; z < m; z++) {
                if (f[x][y][z] == 3) {
                    g[x][z]++;
                }
            }
        }
    }

    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            cout << g[x][y] << ' ';
        }
        cout << '\n';
        
    }

    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> hh;
    a.assign(m, 0);
    b.assign(n, 0);
    for (auto &e : a) cin >> e;
    for (auto &e : b) cin >> e;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> h[i][j];
    }
    solve();
}