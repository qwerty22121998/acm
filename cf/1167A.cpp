#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
string str;

void solve() {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '8') {
            cout << (str.size() - i - 1 >= 10 ? "YES\n" : "NO\n");
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cin >> str;
        solve();
    }
}