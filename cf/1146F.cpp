#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;

const int MAXN = 2e5 + 10;
const int M = 998244353;

int n;
vector<int> a[MAXN];
ll f[MAXN][2] = {0};
void dfs(int u) {
    if (a[u].empty()) {
        f[u][0] = f[u][1] = 1;
        return;
    }
    ll x, y, z;
    x = z = 1;
    y = 0;
    for (auto v : a[u]) {
        dfs(v);
        x *= f[v][0] + f[v][1];
        x %= M;
        y = (y * f[v][0]) % M;
        y = (y + z * f[v][1]) % M;
        z = (z * f[v][0]) % M;
    }
    f[u][0] = (x - y) % M;
    f[u][1] = (x - z) % M;
}

void solve() {
    dfs(1);
    cout << (f[1][0] + M)%M;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        a[u].push_back(i);
    }

    solve();
}