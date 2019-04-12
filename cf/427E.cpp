#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int m, n;
vector<ll> a;
void solve() {
    ll result  = 0;
    for(int i = 0; i < n/2; i += m) {
        result+= 2 * (a[n/2] - a[i]);
    }
    for(int i = n - 1; i > n/2; i-=m) {
        result += 2 * (a[i] - a[n/2]);
    }
    cout << result;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    a.assign(n, 0);
    for(auto &e : a) cin >> e;
    solve();
}