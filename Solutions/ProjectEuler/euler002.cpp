#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXF = 4e16;
vector<ll> f;

void init() {
    f.push_back(1);
    f.push_back(2);
    do {
        f.push_back(f.back() +f[f.size()-2]);
    } while (f.back() < MAXF);

}

void solve() {
     n;
    cin >> n;
    ll sum = 0;
    for(int i = 0; i < f.size() && f[i] <= n ; i++) {
        if (f[i]%2 == 0)
            sum += f[i];
    }
    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(0);


    init();

    int T;
    cin >> T;
    while(T--)
        solve();
}
