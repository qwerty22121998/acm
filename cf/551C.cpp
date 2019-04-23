#include<bits/stdc++.h>

using namespace std;
int n;
string s;
stack < int > open;
deque < int > q;

string bad = ":(";

string solve() {
    if (n % 2) return bad;
    if (s[0] == ')') {
        return bad;
    }
    s[0] = '(';
    if (s.back() == '(') {
        return bad;
    }
    s.back() = ')';
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == ')') {
            if (q.size() == 0 && open.size() == 0) {
                return bad;
            } else {
                if (open.size()) {
                    open.pop();
                } else {
                    s[q.back()] = '(';
                    q.pop_back();
                }

            }
            continue;
        }
        if (s[i] == '?') {
            q.push_back(i);
        }
        if (s[i] == '(') {
            open.push(i);
        }
    }
    while (open.size() && q.size()) {
        int l = open.top();
        int r = q.back();
        if (l > r) return bad;
        open.pop();
        q.pop_back();
        s[r] = ')';
    }
    if (open.size()) return bad;
    if (q.size() % 2) return bad;
    while (q.size()) {
        int l = q.front();
        int r = q.back();
        s[l] = '(';
        s[r] = ')';
        q.pop_back();
        q.pop_front();
    }
    return s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    cout << solve();
}