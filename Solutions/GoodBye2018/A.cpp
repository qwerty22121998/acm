#include<bits/stdc++.h>
using namespace std;

int y, b, r;
int res = -1;
int resy, resb, resr;
void check(int yy, int bb, int rr) {
    if (yy < 0)
        return;
    if (bb < 0)
        return;
    if (rr < 0)
        return;
    if (yy > y || bb > b || rr > r)
        return;
    res = max(res, yy + bb + rr);
}

int main() {
    cin >> y >> b >> r;
    check(y, y + 1, y + 2);
    check(b - 1, b, b + 1);
    check(r - 2, r - 1, r);
    cout << res;




}
