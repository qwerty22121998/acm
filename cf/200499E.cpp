#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;

int n, q;
vector<ii> a;
struct djset {
    vector<int> root;
    int size;
    djset(int n) {
        size = n;
        root.resize(n);
        for (int i = 0; i < n; i++) root[i] = i;
    }

    int getRoot(int u) {
        return root[u] == u ? u : (root[u] = getRoot(root[u]));
    }

    int join(int u, int v) {
        if (getRoot(u) == getRoot(v)) return 0;
        root[getRoot(u)] = getRoot(v);
        return 1;
    }
};

void solve() {
    djset dj(n);
    for (auto e : a) {
        dj.join(e.first, e.second);
    }
    for (int i = 0; i < n; i++) {
        cout << dj.getRoot(i) + 1 << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        a.push_back(ii(u - 1, v - 1));
    }
    solve();
}