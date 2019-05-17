#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;

const int MAXN = 1e5 + 3;

int f[MAXN][20] = {0};

int n;
vector<int> a;

int check(vector<int> b) {
    map<int, int> mp;
    set<int> c;
    for (auto e : b) {
        c.insert(e);
        mp[e]++;
    }
    vector<int> d;
    for (auto e : c) d.push_back(e);
    // for (auto e : d) cout << e << ' ';
    // cout << endl;
    sort(d.begin(), d.end());
    if (d.size() == 1 && b.size() == 1) return 1;
    if (d.size() == 1 && d[0] == 1) return 1;
    if (d.size() > 2) return 0;
    if (d[0] == 1 && mp[d[0]] == 1) return 1;
    if (mp[d[1]] == 1 && d[0] == d[1] - 1) return 1;
    return 0;
}

void solve() {
    f[0][a[0]] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= 10; j++) f[i][j] = f[i - 1][j];
        f[i][a[i]]++;
    }

    for (int i = n - 1; i >= 0; i--) {
        // cout << "i = " << i << endl;
        vector<int> b;
        for (int j = 1; j <= 10; j++) {
            if (f[i][j] != 0) b.push_back(f[i][j]);
        }
        if (check(b)) {
            cout << i + 1;
            return;
        }
    }
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