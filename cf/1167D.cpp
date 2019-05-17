#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;

int n;
string s;

void solve() {
    int res = 0;
    int now = 0;
    vector<int> c(s.size(), 0);
    int cnt[2] = {0};
    cnt[0] = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '(') {
            if (cnt[0] <= cnt[1]) {
                cnt[0]++;
            } else {
                cnt[1]++;
                c[i] = 1;
            }

        } else {
            if (cnt[0] > cnt[1]) {
                cnt[0]--;

            } else {
                c[i] = 1;
                cnt[1]--;
            }
        }
        // cout << cnt[0] << ' ' << cnt[1] << endl;
    }
    for (auto e : c) cout << e;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> s;

    solve();
}