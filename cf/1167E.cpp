#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
int n, x;
vector<int> a;
ll res = 0;
void solve() {
    vector<ii> l, r;
    l.push_back(ii(0, a[0]));
    for(int i = 1; i < n; i++) {
        if (a[i] >= a[i-1]) {
            l.push_back(ii(i, a[i]));
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    a.resize(n);
    for (auto &e : a) cin >> e;

    solve();
}