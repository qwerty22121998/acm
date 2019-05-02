#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
vector<ll> a;
int n;
ll z;
multiset<ll> m;
void solve() {
    for (auto e : a) m.insert(e);
    int res = 0;
    while (m.size()) {
        ll now = *m.begin();
        m.erase(m.begin());
        auto it = m.lower_bound(now + z);
        if (it == m.end()) continue;
        res++;
        m.erase(it);
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> z;
    a.resize(n);
    for (auto &e : a) cin >> e;

    solve();
}