#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;


int n;
vector<ii> a;

void solve() {
    int res = 0;
    a.assign(n, ii(0, 0));
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    a.push_back(ii(0,0));
    int l = a[0].first, r = a[0].second;
    for(int i = 1; i <= n; i++) {
        if (i == n || a[i].first > r) {
            res += r - l + 1;
            l = a[i].first;
            r = a[i].second;
        } else {
            r = max(r, a[i].second);
        }
    }
    cout << res;
}

int main() {
    cin >> n;
    solve();
}
