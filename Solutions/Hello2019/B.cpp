#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int n;
vector<int> f[MAXN];
int a[MAXN];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    f[0].push_back(0);
    for(int i = 1; i <= n; i++) {
        for(auto e : f[i-1]) {
            int now = e + a[i];
            f[i].push_back(now);
            now = (e - a[i] + 360)% 360;
            f[i].push_back(now);
        }
    }
    for(int i = 0; i < f[n].size(); i++) {
        if (f[n][i] == 0) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}
