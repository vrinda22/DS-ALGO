/*Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x. Your task is to complete the function countPairs(), that returns the count of all pairs from both the BSTs whose sum is equal to x.
Input:
The function takes three arguments as input, first the reference pointer to the root(root1) of the BST1, then reference pointer to the root(root2) of the BST2 and last the element X.
There will be T test cases and for each test case the function will be called separately.

Output:
For each test cases print the required number of pairs on new line.

Constraints:
1<=T<=100
1<=N<=103

Example:
Input:
2
7
5 3 7 2 4 6 8
7
10 6 15 3 8 11 18
16
6
10 20 30 40 5 1
5
25 35 10 15 5
30
Output:
3
2
*/
#include <bits/stdc++.h>
using namespace std;

// structure of a node of BST
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
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

int countPairs(Node* root1, Node* root2, int x);

// Driver code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node* root1 = NULL;
        Node* root2 = NULL;
        int n1, n2, k;
        cin>>n1;
        for(int i=0; i<n1; i++)
        {
            cin>>k;
            insert(&root1, k);
        }
        cin>>n2;
        for(int i=0; i<n2; i++)
        {
            cin>>k;
            insert(&root2, k);
        }
        int s;
        cin>>s;
        cout<<countPairs(root1, root2, s)<<"\n";
    }
    return 0;
}
bool searchh(Node *root,int x){
    if(root==NULL)
        return false;
    if(root->data==x)
        return true;
    return searchh(root->left,x) || searchh(root->right,x);
}
int countPairs(Node *root1,Node *root2,int x){
    if(root1==NULL)
        return 0;
    else if(searchh(root2,x-root1->data))
        return 1+ countPairs(root1->left,root2,x) + countPairs(root1->right,root2,x);
    else
        return countPairs(root1->left,root2,x) + countPairs(root1->right,root2,x);
}
