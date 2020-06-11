/*Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.

Input:
First line of input contains the number of test cases T. For each test case, there will be only two line of input, first line contains a string representing the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.
Second line of each test case will contain the integer value k.

Output:
The kth largest element for given input tree.

Your Task:
You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes the root of the BST and an integer K as inputs and returns the Kth largest element in the given BST.

Expected Time Complexity: O(H + K).
Expected Auxiliary Space: O(H).

Constraints:
1 <= T <= 1000
1 <= N <= 1000
1 <= K <= N

Example(To be used only for expected output):
Input:
2
4 2 9 1 3 N 10
3
9 N 10
1
Output:
4
10
*/
#include <bits/stdc++.h>
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

void kthLargest(Node *root, int k);

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

        kthLargest( head, k );
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
void kthLargest(Node *root,int k){
    vector<int> v;
    store(root,v);
    cout<<v[k]<<endl;
}
