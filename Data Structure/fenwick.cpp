#include <bits/stdc++.h>
using namespace std;

// Fenwick tree
template <typename t>
struct Fenwick {
    vector<t> fen;
    int size;
    Fenwick(int n) {
        size = n;
        fen.push_back(0);
        for (int i = 0; i < n; i++) fen.push_back(0);
    }
    void update(int p, t val) {
        for (; p <= size; p += p & -p) fen[p] += val;
    }
    int query(int p) {
        int res = 0;
        for (; p; p -= p & -p) res += fen[p];
        return res;
    }
    int query(int a, int b) {
        int l, r;
        if (a == 0)
            l = 0;
        else
            l = query(a - 1);
        if (b == 0)
            r = 0;
        else
            r = query(b);
        return r - l;
    }
};

int main() {
    Fenwick<int> BIT(3);
    for (int i = 1; i < 4; i++) BIT.update(i, i);
    cout << BIT.query(1, 2);
}
