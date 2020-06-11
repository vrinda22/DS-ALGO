/*Given a BST and a value x, the task is to delete the nodes having values greater than or equal to x.

Input Format:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case consists of an integer N. Then in the next line are N space separated values of the BST nodes. In the next line is an integer x representing the value of the node in the BST.

Output Format:
For each test case, in a new line, print the inorder traversal after deletions.

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= A[] <= 103
1 <= x <= N

Example:
Input:
2
7
20 8 22 4 12 10 14
8
7
20 8 22 4 12 10 14
10
Output:
4
4 8
*/
#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};
Node * deleteNode(Node *, int);
void inorder(Node *root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
Node* search(Node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
       return root;

    // Key is greater than root's key
    if (root->data < key)
       return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val >= (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}
int getCountOfNode(Node *root, int l, int h)
{
    if (!root) return 0;
    if (root->data == h && root->data == l)
        return 1;
    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) + getCountOfNode(root->right, l, h);
    else if (root->data < l)
         return getCountOfNode(root->right, l, h);
    else return getCountOfNode(root->left, l, h);
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;
        root = NULL;
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);
        }

        int s;
        cin>>s;

    Node *R= deleteNode(root,s);
    	inorder(R);
      cout<<endl;
    }
}
Node *deleteNode(Node *root,int key){
    if(root==NULL)
        return NULL;
    if(root->data>=key){
        root=deleteNode(root->left,key);
        return root;
    }
    root->right=deleteNode(root->right,key);
}
