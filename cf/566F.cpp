#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e6;
int f[MAXN] = {0};
int n;
vector<int> a;

void solve() {
    int res = 0;
    for(auto e : a) {
        f[e]++;
        res = max(res,f[e]);
        for(int i = e; i < MAXN; i += e) f[i] = max(f[i], f[e]);
    }
    cout << res;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    a.assign(n, 0);
    for(auto &e : a) cin >> e;
    solve();
}