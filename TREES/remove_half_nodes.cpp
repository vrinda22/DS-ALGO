/*Given A binary Tree. Your task is to remove all the half nodes (which has only one child).

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
Single line output, print the modified tree in inorder traversal.

Your Task:
You don't need to read input or print anything. Your task is to complete the function removeHalfNodes() which takes the root node of the tree as input and returns the root node of the modified tree after removing all the half nodes, ie the ones having just a single child node.
For example consider the below tree.


Nodes 7, 5 and 9 are half nodes as one of their child is Null. We need to remove all such half nodes and return the root pointer of following new tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Binary Tree).

Constraints:
1<=T<=100
1<=N<=104

Example:
Input:
2
7 7 8 2
2 7 5 N 6 N 9 1 11 4
Output:
2 7 8
1 6 11 2 4
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
void inorder(Node * node)
{
    if(node==NULL)
        return;

    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}
Node* RemoveHalfNodes(Node* root) ;

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Node * fresh = RemoveHalfNodes(root);
        inorder(fresh);
        cout<<endl;
    }
    return 1;
}
Node *RemoveHalfNodes(Node *root)
{
    if(root==NULL)
        return root;
    root->left=RemoveHalfNodes(root->left);
    root->right=RemoveHalfNodes(root->right);
    if(root->left && !root->right)
        return root->left;
    if(!root->left && root->right)
        return root->right;
    return root;
}
