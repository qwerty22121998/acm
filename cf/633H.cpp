#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;

const int MAXN = 3e4 + 5;

int n, m, p, num = 0;
int l[MAXN], r[MAXN], a[MAXN], z[MAXN], lst[MAXN], cnt[MAXN], f[MAXN];
long long res[MAXN];
vector<int> v[MAXN];

void solve() {
    f[1] = f[2] = 1 % p;
    for (int i = 3; i <= n; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % p;
    }
    sort(z + 1, z + num + 1);
    num = unique(z + 1, z + num + 1) - z - 1;
    for (int i = 1; i <= n; i++) {
        auto now = lower_bound(z + 1, z + num + 1, a[i]);
        v[now - z].push_back(i);
    }

    for (int i = 1, x; i <= num; i++) {
        x = z[i] % p;
        for (auto it = v[i].begin(); it != v[i].end(); it++) {
            for (int j = 1; j <= m; j++) {
                if (l[j] <= *it && *it <= r[j] && i != lst[j]) {
                    lst[j] = i;
                    res[j] += x * f[++cnt[j]];
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << res[i] % p << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        z[++num] = a[i];
    }

    cin >> m;

    for (int i = 1; i <= m; i++) cin >> l[i] >> r[i];

    solve();
}