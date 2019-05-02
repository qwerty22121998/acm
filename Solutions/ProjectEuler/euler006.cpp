#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e4;

ll sum[MAXN+10] = { 0 };
ll square[MAXN+10] = { 0 };


void gen() {
    for(ll i = 1; i <= 1e4; i++) {
        sum[i] = sum[i-1] + i;
        square[i] = square[i-1] + i*i;
    }
}

void solve() {
    int n;
    cin >> n;
    cout << abs(sum[n]*sum[n] - square[n]) << '\n';
}

int main() {
    gen();
    int T;
    cin >> T;
    while(T--)
        solve();
}
