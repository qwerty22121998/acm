#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6;

int n, m;
int a[MAXN] = {0}, b[MAXN] = {0};
int res = 0;
void solve() {
    b[n] = m;
    sort(b + 1, b + n + 1);
    res = (res - 1) / m + 1;
    cout << res << '\n';
    for (int i = n; i; i--) b[i] -= b[i - 1];

    for (int i = 1; i <= n; i++) {
        cout << b[i] << ' ';
    }
    cout << '\n';
    while(res--) {
        int j = 1;
        for (int i = 1; i <= n; i++) {
            while (j < n && a[j] <= 0) j++;
            cout << j << ' ';
            a[j] -= b[i];
        }
        cout << '\n';
    }
}

int main() {
    // freopen("out.out", "w", stdout);
    // freopen("inp.inp", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        res += a[i];
        b[i] = (b[i - 1] + a[i]) % m;
    }

    solve();
}