#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

typedef pair<int,int> ii;

int n;
map<int, int> mp;
vector<int> a;
vector<int> b;
void solve() {
    for(auto e : a) mp[e]++;
    int res = 0;
    for(auto e : mp) {
        b.push_back(e.second);
    }
    sort(b.begin(), b.end());
    for(int i = 1; i <= b.back(); i++) {
        int pos = b.size() - 1;
        int cur = i;
        int now = cur;
        while (cur % 2 == 0 && pos > 0) {
            cur /= 2;
            pos--;
            if(b[pos] < cur) break;
            now += cur;
        }
        res = max(res, now);
    }
    cout << res;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    
    solve();
}