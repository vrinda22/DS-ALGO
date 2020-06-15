#include <bits/stdc++.h>
using namespace std;

struct node {
    string data;
    struct node *left;
    struct node *right;

    node(string x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

bool isExpression(string &s) {
    if (s == "+" or s == "-" or s == "*" or s == "/") return true;
    return false;
}

int evalTree(node *);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        int p = 0;
        node *root = new node(s[p++]);
        queue<node *> q;
        q.push(root);
        while (!q.empty()) {
            node *f = q.front();
            q.pop();
            node *l, *r;
            if (isExpression(f->data)) {
                l = new node(s[p++]);
                r = new node(s[p++]);
                f->left = l;
                f->right = r;
                q.push(l);
                q.push(r);
            }
        }

        cout << evalTree(root) << endl;
    }
}
int toInt(string s){
    int num=0;
    if(s[0]!='-')
        for(int i=0;i<s.length();i++)
            num=num*10 + (int(s[i])-48);
    else
    for(int i=1;i<s.length();i++){
        num=num*10 +(int(s[i])-48);
        num=num*-1;
    }
    return num;
}
int evalTree(node *root){
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return toInt(root->data);
    int lval=evalTree(root->left);
    int rval=evalTree(root->right);
    if(root->data == "+")
        return lval+rval;
    if(root->data == "-")
        return lval-rval;
    if(root->data == "*")
        return lval*rval;
    return lval/rval;
}
