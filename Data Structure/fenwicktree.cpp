#include<bits/stdc++.h>
using namespace std;

struct Fenwick {
    vector<int> fen;
    int size;
    Fenwick(int n) {
        size = n;
        fen.push_back(0);
        for(int i = 0; i < n; i++) fen.push_back(0);
    }
    void update(int p, int val) {
        for(int i = p; i <= size; i+= i & -i)
            fen[i] += val;
    }
    int query(int p) {
        int res = 0;
        for(int i = p; i; i -= i & -i)
            res+=fen[i];
        return res;
    }
    int query(int a, int b) {
        int l, r;
        if (a==0) l = 0;
        else l = query(a-1);
        if (b==0) r = 0;
        else r = query(b);
        return r-l;
    }
};


int main() {
    Fenwick BIT(3);
    for(int i = 1; i < 4; i++) BIT.update(i,i);
    cout << BIT.query(1,2);
}
