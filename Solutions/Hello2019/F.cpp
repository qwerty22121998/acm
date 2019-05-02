#include<bits/stdc++.h>
using namespace std;

int n, q;
unordered_map<int, unordered_map<int, int> > t;

unordered_map<int, int> m;
int gcd[7001][7001] = {0};

int GCD(int a, int b) {
    if (gcd[a][b] != 0)
        return gcd[a][b];
    return gcd[a][b] = (b == 0 ? a : GCD(b, a %b));
}

int v, x, y, z;

void cs1() {
    cin >> x >> v;
    m.clear();
    m[v] = 1;
    t[x] = m;
    //cout << x << " : ";
    //cout << "- " << v << " " << t[x][v] << endl;
}

void cs2() {
    //cout << "CASE2\n";
    cin >> x >> y >> z;
    m.clear();
    for(auto e : t[y]) {
        m[e.first] += e.second;
        //cout << e.first << " + " << e.second << endl;
    }
    for(auto e : t[z]) {
        m[e.first] += e.second;
        //cout << e.first << " + " << e.second << endl;
    }
    //cout << x << " : ";
    t[x] = m;
    //for(auto e : t[x]) {
    //    cout << "- " << e.first << " " << e.second << endl;
    //}
}

void cs3() {

    cin >> x >> y >> z;
    m.clear();
    for(auto e1 : t[y]) {
        for(auto e2 : t[z]) {
            int now = GCD(e1.first, e2.first);
            m[now] = e1.second * e2.second;
        }
    }
    t[x] = m;
    //cout << x << " : ";
    //for(auto e : t[x]) {
    //    cout << "- " << e.first << " " << e.second << endl;
    //}
}

void cs4() {
    cin >> x >> v;

    //cout << x << " contain " << v ;
    cout << t[x][v]%2;
    //cout << endl;
}


int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("F.inp","r",stdin);
    cin >> n >> q;
    for(int i = 0; i < q; i++) {
        int T;
        cin >> T;
        switch (T) {
        case 1 :
            cs1();
            break;
        case 2:
            cs2();
            break;
        case 3:
            cs3();
            break;
        case 4:
            cs4();
            break;
        }
    }
}
