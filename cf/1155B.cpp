#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

typedef pair<int,int> ii;

int n;
string s;
vector<int> f;
const string NO = "NO";
const string YES = "YES";

string solve() {
    int cnt = (n - 11)/2;
    int last = -1;
    for(int i = 0; i < n; i++) {
        if (s[i] == '8') {
            if (!f.size()) f.push_back(i);
            else f.push_back(i - last - 1);
            last = i;
        }
    }
    // for(int i = 0; i < f.size(); i++) cout << f[i] << " ";
    // cout << endl;
    if (f.size() <= cnt) return NO;
    int sum = f[0];
    for(int i = 1; i <= cnt; i++) {
        sum += f[i];
    }
    // cout << sum << endl;
    return sum <= cnt ? YES : NO;
}
/*
15
181881888888888
*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    cout << solve();
}