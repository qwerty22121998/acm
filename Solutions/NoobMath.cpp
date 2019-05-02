#include<bits/stdc++.h>
using namespace std;
const int MAXN = 9;
const char x[MAXN] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
map<string, int> pass;
string generated = "00000";
int cnt = 0;

void checkCondition() {
    if (generated[0] == '0') return;
    for(int i = 0; i < generated.size()-1; i++) {
        for(int j = i + 1; j < generated.size(); j++) 
            if (generated[i] == generated[j]) return;
    }
    if ((generated.back() - '0') % 2) return;
    if (pass[generated] != 0) return;
    cnt++;
    pass[generated]++;

}

void generate(int pos) {
    if (pos == 5) {
        checkCondition();
        return;
    }
    for(int i = 0; i < MAXN; i++) {
        generated[pos] = x[i];
        generate(pos+1);
    }
}


int main() {
    generate(0);
    cout << cnt;
}