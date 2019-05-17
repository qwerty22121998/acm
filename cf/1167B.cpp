#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
map<vector<int>, vector<int> > mp;

int H(int a, int b, int c, int d) {
    return a * c - d + c * b - a * c - b + c - 7 * d - a + 2 * b;
}

void solve() {
    vector<int> a;
    a.push_back(4);
    a.push_back(8);
    a.push_back(15);
    a.push_back(16);
    a.push_back(23);
    a.push_back(42);
    do {
        vector<int> now{a[0] * a[1], a[0] * a[2], a[3] * a[4], a[3] * a[5]};
        if (mp[now].size()) assert(true);
        mp[now] = a;
    } while (next_permutation(a.begin(), a.end()));
    int a01, a02, a34, a35;
    cout << "? 1 2\n";
    fflush(stdout);
    cin >> a01;
    cout << "? 1 3\n";
    fflush(stdout);
    cin >> a02;
    cout << "? 4 5\n";
    fflush(stdout);
    cin >> a34;
    cout << "? 4 6\n";
    fflush(stdout);
    cin >> a35;
    cout << "! ";
    vector<int> now{a01, a02, a34, a35};
    for (auto e : mp[now]) {
        cout << e << " ";
    }
}

int main() {
    ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    solve();
}