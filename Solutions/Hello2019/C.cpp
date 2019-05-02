#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<string> a;
map<int, ll> p;
map<int, ll> s;
ll z = 0;
int pre(string s) {
    int val = 0;
    for(auto e : s) {
        if (e == '(')
            val++;
        else
            val--;
        if (val < 0)
            return -1;
    }
    return val;
}

int suf(string s) {
    int val = 0;
    reverse(s.begin(), s.end());
    for(auto e : s) {
        if (e == ')')
            val++;
        else
            val--;
        if (val < 0)
            return -1;
    }
    return val;
}


int main() {
    cin >> n;
    a.assign(n, "");
    for(auto &e : a)
        cin >> e;
    ll res = 0;
    set<int> l, r;
    for(int i = 0; i < n; i++) {
        int pp = pre(a[i]);
        int ss = suf(a[i]);
        //cout << pp << " " << ss << endl;
        if (pp == 0 || ss == 0) {
            z++;
            continue;
        }
        if (pp > 0) {
            p[pp]++;
            l.insert(pp);
        }
        if (ss > 0) {
            s[ss]++;
            r.insert(ss);
        }
    }
    for(auto a : l) {
        res+= min(p[a], s[a]);
    }
    res+= z/2;
    cout << res;




}
