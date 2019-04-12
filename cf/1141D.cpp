#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int n;
string a, b;
vector<int> l[2000];
vector<int> r[2000];
vector<ii> result;
void solve() {
    for(int i = 0; i < n; i++) {
        l[a[i]].push_back(i);
    }
    for(int i = 0; i < n; i++) {
        char now = b[i];
        if (now == '?') {
            r['?'].push_back(i);
            continue;
        }
        if (l[now].size()) {
            int pos = l[now].back();
            l[now].pop_back();
            a[pos] = '.';
            b[i] = '.';
            result.push_back(ii(pos, i));
        }
    }

    if (l['?'].size()) {
        for(int i = 0; i < b.size(); i++) {
            if (b[i]!= '.' && b[i]!='?' && l['?'].size()) {
                result.push_back(ii(l['?'].back(), i));
                l['?'].pop_back();
            }
        }
    }

    if (r['?'].size()) {
        for(int i = 0; i < a.size(); i++) {
            if (a[i] != '.' && a[i] != '?' && r['?'].size()) {
                result.push_back(ii(i, r['?'].back()));
                r['?'].pop_back();
            }
        }
    }

    while (r['?'].size() && l['?'].size()) {
        result.push_back(ii(l['?'].back(), r['?'].back()));
        l['?'].pop_back();
        r['?'].pop_back();
    }


    // cout << a << '\n' << b << endl;
    cout << result.size() << '\n';
    for(auto e : result) {
        cout << ++e.first << ' ' << ++e.second << '\n';
    }
}

int main() {
    cin >> n;
    cin >> a >> b;
    solve();

}