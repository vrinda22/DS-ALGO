/*Given a Binary Search Tree of size N, your task is to complete the function changeKey() that change old key value present in the tree and changes it to new key value.
Input:
The function takes three arguments, reference pointer to the root node of the BST, old key value of the node and a new key value.
There will be T test cases and for each test case the function will be called separately.

Output:
For each test case output the Inorder traversal of the Tree.

Constraints:
1<=T<=100
1<=N<=500

Example:
Input:
1
7
20 8 22 4 12 10 14
8 1
Output:
1 4 10 12 14 20 22
*/
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
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

void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

struct node* insert(struct node* root, int key)
{

	if (root == NULL) return (new node(key));
	if (key < root->key)
		root->left = insert(root->left, key);
	else
		root->right = insert(root->right, key);
	return root;
}

// Function to change a key value in Binary Search Tree
struct node *changeKey(struct node *root, int oldVal, int newVal);

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        struct node *root = NULL;
        int n, temp, oldKey, new_key;
        cin>>n;
        while(n--)
        {
            cin>>temp;
            root = insert(root, temp);
        }
        cin>>oldKey;
        cin>>new_key;
        root = changeKey(root, oldKey, new_key);
        inorder(root);
        printf("\n");
    }
	return 0;
}
void store(struct node *root,vector<int>&v){
    if(root==NULL)
        return;
    store(root->left,v);
    v.push_back(root->key);
    store(root->right,v);
}
struct node *changeKey(node *root,int old,int neww){
    vector<int> v;
    store(root,v);
    for(int i=0;i<v.size();i++){
        if(v[i]==old){
            v[i]=neww;
            break;
        }
    }
    sort(v.begin(),v.end());
    struct node *temp=NULL;
    for(int i=0;i<v.size();i++)
        temp=insert(temp,v[i]);
    return temp;
}
