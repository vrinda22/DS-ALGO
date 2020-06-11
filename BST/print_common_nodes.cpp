/*Given two Binary Search Trees(without duplicates). Find need to print the common nodes in them. In other words, find intersection of two BSTs

Input:
The first line of input contains the number of test cases T. For each test case, there will be 2 lines of input. Each line will contain a string representing a tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.
Output:
For each test case, in a new line, print the nodes common to both BSTs in sorted order.

Your Task:
You don't need to read input or print anything. Your task is to complete the function printCommon() that takes roots of both the BSTs as input and returns an array containing the intersection of the 2 BSTs in a sorted order.

Expected Time Complexity: O(N1 + N2) where N1 and N2 are the sizes of the 2 BSTs.
Expected Auxiliary Space: O(N1 + N2)

Constraints:
1 <= T <= 400
1 <= N <= 103

Example:
Input:
2
5 1 10 0 4 7 N N N N N N 9
10 7 20 4 9
10 2 11 1 3
2 1 3
Output:
4 7 9 10
1 2 3
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

void printCommon(Node *root1, Node *root2);

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root1 = buildTree(s);

        getline(cin,s);
        Node* root2 = buildTree(s);

        printCommon(root1, root2);
        cout<< endl;
    }

	return 1;
}
void inorder(Node *root,map<int,int>&v){
    if(root==NULL)
        return;
    inorder(root->left,v);
    v[root->data]++;
    inorder(root->right,v);
}
void printCommon(Node *root1,Node *root2){
    map<int,int> v;
    v.clear();
    inorder(root1,v);
    inorder(root2,v);
    for(auto it=v.begin();it!=v.end();it++){
        if(it->second==2){
            cout<<it->first<<" ";
        }
    }
}
