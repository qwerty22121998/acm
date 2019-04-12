#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a;

void solve() {
    if (a < 3) {
        cout << -1;
        return;
    }
    ll b, c;
    if (a%2) {
        b = a*a-1;
        if (b%2) {
            cout << -1;
            return;
        }
        b/=2;
        c = b + 1;
    } else {
        b = (a/2)*(a/2)-1;
        c = b + 2;
    }
    cout << b << ' ' << c;
}

int main() {
    cin >> a;
    solve();

}