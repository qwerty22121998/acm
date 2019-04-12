#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;

void solve() {
    ll res = 0;
    ll g5 = (((n * (n - 1) / 2) * (n - 2) / 3) * (n - 3) / 4) * (n - 4) / 5;
    ll g6 = ((((n * (n - 1) / 2) * (n - 2) / 3) * (n - 3) / 4) * (n - 4) / 5) * (n - 5) / 6;
    ll g7 = (((((n * (n - 1) / 2) * (n - 2) / 3) * (n - 3) / 4) * (n - 4) / 5) * (n - 5) / 6) * (n - 6) / 7;
    res = g5+g6+g7;
    cout << res;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    
    solve();
}