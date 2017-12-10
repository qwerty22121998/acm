#include<bits/stdc++.h>
using namespace std;
const int maxc = 26;

struct Trie {
    struct node {
        node* p;
        node* son[maxc];
        int PRF, EOW;
    };
    node * root;
    Trie() {
        root = newNode();
    }
    node *newNode() {
        node *tmp = new node;
        for(int i= 0; i < maxc; i++) tmp->son[i] = NULL;
        tmp->p = NULL;
        tmp->PRF = 0;
        tmp->EOW = 0;
    }
    void insert(const string& s) {
        node * now = root;
        for(int i = 0; i < s.size(); i++) {
            int k = s[i] - 'a';
            now->PRF++;
            if (!now->son[k]) {
                now->son[k] = newNode();
                now->son[k]->p = now;
            }
            now = now->son[k];
        }
        now->EOW++;
    }

    int find(const string& s) {
        node * now = root;
        for(int i = 0; i < s.size(); i++) {
            int k = s[i] - 'a';
            if (!now->son[k]) return 0;
            now = now->son[k];
        }
        return 1;
    }

};

int main() {
    Trie T;
    T.insert("example");
    cout << T.find("example") << endl;
    cout << T.find("foo") << endl;
}
