#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> prime;


const int MAXN = 2e6+5;
int f[MAXN];


ll LP(ll n) {
    ll on = n;
    for(ll i = 2; i <= sqrt(on); i++) {
        while (n % i == 0) n /= i;
        if (n == 1) return i;
    }
    return n;
}

void solve() {
    ll n;
    cin >> n;
    cout << LP(n) << '\n';

}

int main() {
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
        solve();
}
