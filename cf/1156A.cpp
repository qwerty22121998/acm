#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
int n;
vector<int> a;
ll res;

int get(int pre, int a, int b) {
    // a circle
    if (a == 1) {
        // b triangle
        if (b == 2) return 3 - (pre == 3);
        // b square
        if (b == 3) return 4;
    }
    // a triangle
    if (a == 2) {
        // b circle
        if (b == 1) return 3;
        // b square
        if (b == 3) return -1;
    }
    // square
    if (a == 3) {
        // b circle
        if (b == 1) return 4;
        // b triangle
        if (b == 2) return -1;
    }
    return 0;
}

void solve() {
    res = 0;
    for (int i = 1; i < n; i++) {
        ll now = 0;
        if (i != 1)
            now = get(a[i - 2], a[i - 1], a[i]);
        else
            now = get(0, a[i - 1], a[i]);

        if (now == -1) {
            cout << "Infinite";
            return;
        }
        res += now;
    }
    cout << "Finite\n" << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    a.resize(n);
    for (auto &e : a) cin >> e;
    solve();
}