/*Given a Binary Search Tree of size N, that may be unbalanced. Your task is to complete the function buildBalancedTree(), that convert the given BST into a balanced BST that has minimum possible height.
Input:
The function takes a single argument as input, the reference pointer to the root of the Binary Search Tree.
There are T, test cases and for each test case the function will be called separately.

Output:
For each test case output will be the new height of the BST.

Constraints:
1<=T<=100
1<=N<=200

Example:
Input:
2
3
30 20 10
5
10 8 7 6 5
Output:
2
3
*/
#include <bits/stdc++.h>
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

Node* insert(struct Node* node, int key){
	if (node == NULL) return new Node(key);
	if (key < node->data)
		node->left = insert(node->left, key);
	else if (key > node->data)
		node->right = insert(node->right, key);
	return node;
}

void preOrder(Node* node)
{
	if (node == NULL)return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

int height(struct Node* node)
{
   if (node==NULL) return 0;
   else
   {
       int lDepth = height(node->left);
       int rDepth = height(node->right);
       if (lDepth > rDepth) return(lDepth+1);
       else return(rDepth+1);
   }
}

Node* buildBalancedTree(Node* root);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        struct Node *root = NULL;
        int n, temp;
        cin>>n;
        while(n--)
        {
            cin>>temp;
            root = insert(root, temp);
        }
        // cout<<height(root)<<endl;
        root = buildBalancedTree(root);
        cout<<height(root)<<endl;
    }
	return 0;
}
void store(Node *root,vector<Node *>&v){
    if(root==NULL)
        return;
    store(root->left,v);
    v.push_back(root);
    store(root->right,v);
}
Node *build(vector<Node *>&v,int start,int endd){
    if(start>endd)
        return NULL;
    int mid=(start+endd)/2;
    Node *root=v[mid];
    root->left=build(v,start,mid-1);
    root->right=build(v,mid+1,endd);
    return root;
}
Node *buildBalancedTree(Node *root){
    vector<Node *> v;
    store(root,v);
    int n=v.size();
    return build(v,0,n-1);
}
