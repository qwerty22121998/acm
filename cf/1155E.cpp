#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

typedef pair<int,int> ii;

#define IP Interpolation
namespace Interpolation {
    const int mod = (int) 1e9 + 7;
    const int maxn = 1e5 + 5;
    int a[maxn];
    int fac[maxn];
    int ifac[maxn];
    int prf[maxn];
    int suf[maxn];

    int fpow(int n, int k) {
        int r = 1;
        for (; k; k >>= 1) {
            if (k & 1) r = (long long) r * n % mod;
            n = (long long) n * n % mod;
        }
        return r;
    }
    void upd(int u, int v) {
        a[u] = v;
    }
    void build() {
        fac[0] = ifac[0] = 1;
        for (int i = 1; i < maxn; i++) {
            fac[i] = (long long) fac[i - 1] * i % mod;
            ifac[i] = fpow(fac[i], mod - 2);
        }
    }
    //Calculate P(x) of degree k - 1, k values form 1 to k
    //P(i) = a[i]
    int calc(int x, int k) {
        prf[0] = suf[k + 1] = 1;
        for (int i = 1; i <= k; i++) {
            prf[i] = (long long) prf[i - 1] * (x - i + mod) % mod;
        }
        for (int i = k; i >= 1; i--) {
            suf[i] = (long long) suf[i + 1] * (x - i + mod) % mod;
        }
        int res = 0;
        for (int i = 1; i <= k; i++) {
            if (!((k - i) & 1)) {
                res = (res + (long long) prf[i - 1] * suf[i + 1] % mod * ifac[i - 1] % mod * ifac[k - i] % mod * a[i]) % mod;
            }
            else {
                res = (res - (long long) prf[i - 1] * suf[i + 1] % mod * ifac[i - 1] % mod * ifac[k - i] % mod * a[i] % mod + mod) % mod;
            }
        }
        return res;
    }
}

const int mod = (int) 1e6+3;

vector<ii> guess;

void solve() {
    IP::build();
    for(int i = 0; i <= 20; i++) {
        cout << "? " << i << endl;
        int resp;
        cin >> resp;
        IP::a[i] = resp;
        guess.push_back(ii(i, resp));
    }
    for(int i = 0; i < mod; i++) {
        if (IP::calc(i, 20)%mod == 0) {
            cout << "! " << i;
            return;
        }
    }
    cout << "! -1";
    
}

int main() {
    freopen("1155E.inp","r",stdin);
    ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    
    solve();
}