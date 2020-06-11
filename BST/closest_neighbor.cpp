/*Given a binary search tree and a number N. Your task is to complete the function findMaxforKey(), that find's the greatest number in the binary search tree that is less than or equal to N. Print the value of the element if it exists otherwise print -1.
Input:
The function takes two argument as input, the reference pointer to the root of the binary search tree and integer value N.
There will be T, test cases and for each test case the function will be called separately.

Output:
For each test case print the greatest number in the binary search tree that is less than or equal to N

Constraints:
1<=T<=100
1<=N<=103

Example:
Input:
2
5
5 1 3 7 9
8
9
5 2 1 3 12 9 21 19 25
4
Output:
7
3
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;

	Node(int x){
	    key = x;
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

    if(val < (*tree)->key)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->key)
    {
        insert(&(*tree)->right, val);
    }

}


int mini=INT_MAX;
int findMaxForN(Node* root, int N,int sizee);


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node* root=NULL;
        int n, k;
        cin>>n;
        mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            cin>>k;
            insert(&root, k);
        }
        int s;
        cin>>s;

       cout<<findMaxForN(root,s,n)<<endl;

    }
    return 0;
}
int findMaxForN(Node *root,int N,int sizee){
    if(root == NULL)
        return -1;
    else if(root->key == N)
        return N;
    else if(root->key < N){
        int right = findMaxForN(root->right, N, sizee);
        if(right == -1)
            return root->key;
    }
    else{
         return findMaxForN(root->left, N, sizee);
    }
}
