#include<bits/stdc++.h>
using namespace std;

int m, n;

void solve() {
    int a = min(m, n);
    cout << a+1 << '\n';
    for(int i = 0; i <= a; i++) {
        cout << i << " " << a - i << '\n';
    }
}

int main() {
    cin >> n >> m;
    solve();
}