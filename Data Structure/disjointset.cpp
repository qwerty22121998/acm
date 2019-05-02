#include <bits/stdc++.h>
using namespace std;

struct djset {
    vector<int> root;
    int size;
    djset(int n) {
        size = n;
        root.resize(n);
        for (int i = 0; i < n; i++) root[i] = i;
    }

    int getRoot(int u) {
        return root[u] == u ? u : (root[u] = getRoot(root[u]));
    }

    int join(int u, int v) {
        if (getRoot(u) == getRoot(v)) return 0;
        root[getRoot(u)] = getRoot(v);
        return 1;
    }
};

int main() {}