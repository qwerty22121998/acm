#include<bits/stdc++.h>
using namespace std;


string ontbl;
string c[5];

string check() {
    for(int i = 0; i < 5; i++) {
        if (c[i][0] == ontbl[0] || c[i][1] == ontbl[1]) return "YES";
    }
    return "NO";
}

int main() {
    cin >> ontbl;
    for(int i = 0; i < 5; i++)
        cin >> c[i];
    cout << check();

}


