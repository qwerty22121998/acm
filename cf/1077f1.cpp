#include <bits/stdc++.h>
using namespace std;

const int MAXN = 205;
typedef long long ll;


typedef pair<int, int> ii;
vector< vector<ll> > f;

int n, k, x;
vector<ll> a;
void solve() {
    f.resize(n+1, vector<ll>(x+1, -1));
    f[0][x] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < x; j++) {
            for (int p = 1; p <= k; p++) {
                if (i - p < 0) break;
                if (f[i - p][j + 1] == -1) continue;
                f[i][j] = max(f[i][j], f[i - p][j + 1] + a[i - 1]);
            }
        }
    }
    ll res = -1;
    for (int i = n - k + 1; i <= n; i++) {
        for (int j = 0; j < x; j++) res = max(res, f[i][j]);
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> x;
    a.assign(n, 0);
    for (auto& e : a) cin >> e;
    solve();
}