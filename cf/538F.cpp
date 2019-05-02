#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;

const int MAXN = 2e5 + 100;
int f[MAXN];
int n;
vector<int> a;
vector<ii> w;

int sum(int x) {
    int res = 0;
    while (x > 0) {
        res += f[x];
        x &= x + 1;
        x--;
    }
    return res;
}

void add(int x, int z) {
    
    while (x < MAXN) {
        f[x] += z;
        x |= x + 1;
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        w.push_back(ii(a[i], i));
    }
    sort(w.begin(), w.end());
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    a.assign(n, 0);
    for (auto &e : a) cin >> e;

    solve();
}