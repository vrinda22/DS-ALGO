/*Given postorder traversal of a Binary Search Tree, you need to complete the function constructTree() which will create a BST. The output will be the inorder of the constructed BST.

Input:
The constructTree() method consist of two arguments as input, the array consisting of the post order traversal and the size of the array.

Output:
Print the Inorder traversal of the constructed BST.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
6
1 7 5 50 40 10
9
216 823 476 429 850 93 18 975 862

Output:
1 5 7 10 40 50
18 93 216 429 476 823 850 862 975
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

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
}
int main ()
{
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}
Node *construct(Node *root,int data){
    if(root==NULL){
        root=new Node(data);
        root->data=data;
        root->left=root->right=NULL;
        return root;
    }
    if(root->data>data)
        root->left=construct(root->left,data);
    else
        root->right=construct(root->right,data);
}
Node *constructTree(int post[],int n){
    Node *root=NULL;
    for(int i=0;i<n;i++)
        root=construct(root,post[i]);
    return root;
}
