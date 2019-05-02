#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

vector<ll> gt;
ll n;

void solve() {
    gt.push_back(1);
    for(ll i = 1; i <= n; i++)
        gt.push_back((gt.back()*i)%MOD);
    ll res = gt[n];
    ll pre = 1;
    for(ll i = n; i > 0; i--) {
        pre = (pre * i)%MOD;
        res += (pre*(gt[i-1]-1))%MOD;
        res%= MOD;
    }
    cout << res;
}

int main() {

    cin >> n;
    solve();

}
