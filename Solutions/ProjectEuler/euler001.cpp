#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    n--;
    ll div3 = n/3;
    ll div5 = n/5;
    ll div15 = n/15;
    cout << 3 * div3*(div3+1)/2 + 5*div5*(div5+1)/2 - 15*div15*(div15+1)/2 << "\n";

}

int main() {
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}

