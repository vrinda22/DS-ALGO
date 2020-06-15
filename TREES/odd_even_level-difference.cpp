/*Given a a Binary Tree, your task is to complete the function getLevelDiff which  returns the difference between the sum of nodes at odd level and the sum of nodes at even level . The function getLevelDiff  takes only one argument  ie the root of the binary tree .

       2
     /    \
    3     5
For the above tree the odd level sum is 2 and even level sum is 8 thus the difference is 2-8=-6

Input:

First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
The function should return an integer denoting the difference between the sum of nodes at odd level and the sum of nodes at even level

Your Task:
This is a function problem. You don't have to take input. Just complete the function getLevelDiff() that takes node as parameter and returns the answer. The printing is done by the driver code only.

Expected Time Complexity : O(n)

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 105

Example:
Input
2
1 2 3
10 20 30 40 60
Output
-4
60
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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


int getLevelDiff(Node *root);

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



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        cout<<getLevelDiff(root);
        cout << endl;
    }
    return 0;
}
int getLevelDiff(Node *root)
{
   if(root==NULL)
    return 0;
   return root->data-getLevelDiff(root->left)-getLevelDiff(root->right);
}


