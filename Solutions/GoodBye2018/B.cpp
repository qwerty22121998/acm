#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define x first
#define y second
int n;
vector<ii> o;
vector<ii> c;
map<ii, int> p;

void solve() {
    for(int i = 0; i < n; i++) {
        p[ii(o[0].x + c[i].x, o[0].y + c[i].y)]++;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ii now = ii(o[i].x + c[j].x, o[i].y + c[j].y);
            if (p[now] != 0)
                p[now]++;

        }
    }
    for(auto e : p) {
        if (e.y == n) {
            cout << e.x.x << " " << e.x.y;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        o.push_back(ii(x, y));
    }
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        c.push_back(ii(x, y));
    }
    solve();
}
