#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6;

typedef long long ll;

int factor[MAXN+5];
int f[MAXN+5] = {0};
 
// 100 = 2^2*5*2
// 3 * 3 - 2 = 7
map<int, ll> prime;
int NPF(int a) {
    prime.clear();
    if (f[a] != 0) return f[a];
    vector<ll> fac;
    while (factor[a] > 1) {
        prime[factor[a]]++;
        a/= factor[a]; 
    }
    ll res = 1;
    int size = 0;
    for(auto &kv : prime) {
        res *= kv.second + 1;
        // cout << kv.first << " : " << kv.second << '\n';
        size++;
    }
    return f[a] = res - size;
}


void eratos() {
    factor[1] = 0;
    for(int i = 0; i <= MAXN; i++) factor[i] = i;
    for(ll i = 2; i <= sqrt(MAXN); i++) {
        if (factor[i] != i) continue;
        ll j = i*i;
        while (j <= MAXN) {
            factor[j] = i;
            j+=i;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    cout << NPF(n) << '\n';
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    eratos();
    int Q;
    cin >> Q;
    while (Q--) solve();
}