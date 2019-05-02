#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;

typedef pair<int, ii> iii;

struct djset {
    vector<int> root;

    int size;
    djset(int n) {
        size = n;
        root.resize(n);
        for (int i = 0; i < n; i++) root[i] = -1;
    }

    int getRoot(int u) {
        if (root[u] == -1) return -1;
        return root[u] == u ? u : (root[u] = getRoot(root[u]));
    }

    int join(int u, int v) {
        if (getRoot(u) == getRoot(v)) return 0;
        root[getRoot(u)] = getRoot(v);
        return 1;
    }
};

vector<ii> s[2];
int n;
ll res = 0;
djset dj[2];
void solve(vector<ii> a) {
    djset d(n + 1);
    for (auto e : a) {
        d.root[e.first] = e.first;
        d.root[e.second] = e.second;
    }
    for (auto e : a) d.join(e.first, e.second);

    map<int, ll> m;
    for (int i = 0; i < n; i++) m[d.getRoot(i)]++;

    for (int i = 0; i < n; i++) res += m[i] * (m[i]-1);
    dj[a.back().second] = d;
}

void solve() {
    solve(s[0]);
    solve(s[1]);
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        s[w].push_back(ii(u, v));
        s[w].push_back(ii(v, u));
    }
    solve();
}