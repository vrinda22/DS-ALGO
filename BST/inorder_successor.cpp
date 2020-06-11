/*Given a BST,  and a reference to a Node x in the BST. Find the Inorder Successor of the given node in the BST.

Input:
First line of input contains the number of test cases T. For each test case, there will be only two line of input, first line contains a string representing the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.
Second line of each test case will contain the integer value K. K is the data of the reference node.

Output:
For each test case output will be the Inorder successor of the given node. If no such successor is present output will be -1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function inOrderSuccessor(). This function takes the root node and the reference node as argument and returns the node that is inOrder successor of the reference node. If there is no successor, return null value.

Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 1000
1 <= N <= 1000, where N is number of nodes
1 <= A[ ] <= 10000

Example:
Input:
2
20 8 22 4 12 N N N N 10 14
8
20 8 22 4 12 N N N N 10 14
10
Output:
10
12
*/
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

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
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
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

Node * inOrderSuccessor(Node *, Node* );

int main()
{
    int t;
    cin>>t;
    getchar();

    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);

        int k;
        cin>>k;
        getchar();

        Node* kNode = search( head, k );
        Node* suc = inOrderSuccessor(head, kNode);

        if( suc == NULL ) cout<< "-1";
        else cout<< suc->data;
        cout << endl;
    }

    return 1;
}
void store(Node *root,vector<int>&v){
    if(root==NULL)
        return;
    store(root->left,v);
    v.push_back(root->data);
    store(root->right,v);
}
Node *inOrderSuccessor(Node *root,Node *x){
    if(root==NULL)
        return NULL;
    vector<int> v;
    store(root,v);
    for(int i=0;i<v.size();i++){
        if(v[i]>x->data){
            Node *temp=new Node();
            temp->data=v[i];
            temp->left=temp->right=NULL;
            return temp;
        }
    }
    return NULL;
}
