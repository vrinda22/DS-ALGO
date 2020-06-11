/*Given a Binary Search Tree (BST), write a function isTripletPresent() that returns true if there is a triplet in given BST with sum equals to 0, otherwise returns false.

Input:
First line consists of T test case. First line of every test case consists of N, denoting the number of nodes in bst. Second line of every test case consists of nodes.

Output:
Single line output, return true if triplet found else false.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
5
5 -8 -2 10 11
4
1 3 -2 0 5
Output:
1
0
*/
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int key;
	struct node *left;
	struct node *right;

	node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

bool isTripletPresent(node *root);

node* insert(node* root, int key)
{
    if (root == NULL)
       return (new node(key));
    if (root->key > key)
       root->left = insert(root->left, key);
    else
       root->right = insert(root->right, key);
    return root;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		node* root = NULL;
		while(n--){
			int a;
			cin>>a;
			root = insert(root, a);
		}
		if (isTripletPresent(root))
			printf("1\n");
		else
			printf("0\n");
	}
    return 0;
}
void store(node *root,vector<int>&v){
    if(root==NULL)
        return;
    store(root->left,v);
    v.push_back(root->key);
    store(root->right,v);
}
bool trip(vector<int> &v){
    for(int i=0;i<v.size();i++){
        int l=i+1;
        int r=v.size()-1;
        while(l<r){
            if(v[l]+v[r]+v[i]==0)
                return true;
            else if(v[l]+v[r]+v[i]<0)
                l++;
            else
                r--;
        }
    }
    return false;
}
bool isTripletPresent(node *root){
    vector<int>v;
    store(root,v);
    return trip(v);
}
