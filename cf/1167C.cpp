#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
int n, m;

vector<vector<int> > a;
vector<int> root;
vector<int> res;

int getRoot(int u) { return root[u] == u ? u : root[u] = getRoot(root[u]); }

void join(int u, int v) {
    int ru = getRoot(u);
    int rv = getRoot(v);
    if (ru == rv) return;
    root[ru] = rv;
}

void solve() {
    root.resize(n);
    res.assign(n, 0);
    for (int i = 0; i < root.size(); i++) {
        root[i] = i;
    }
    for (auto e : a) {
        for (int i = 1; i < e.size(); i++) {
            join(e[i - 1], e[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        res[getRoot(i)]++;
    }
    for (int i = 0; i < n; i++) res[i] = res[getRoot(i)];
    for (int i = 0; i < n; i++) cout << res[i] << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    a.resize(m);
    for (auto &e : a) {
        int c;
        cin >> c;
        e.resize(c);
        for (auto &ee : e) {
            cin >> ee;
            ee--;
        }
    }

    solve();
}