/*Given a binary tree, your task is to complete the function minDepth which takes one argument the root of the binary tree and prints the min depth of  binary tree .

          1
       /    \
     2       3
   /
4

For the tree above the min depth is 2 ie 1 3

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
The output will be an integer denoting the min depth of the binary tree.

Your Task:
This is a function problem. You don't have to take input. Just complete the function minDepth() that takes node as parameter and returns the minimum depth. Output is printed by the driver code itself.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 105

Example:
Input:
2
1 3 2 4
10 20 30 N 40 N 60 N N 2
Output:
2
3
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

int minDepth(Node* node);

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        // getline(cin, ch);

        cout << minDepth(root) << endl;
        // cout<<"~"<<endl;
    }
    return 0;
}
int minDepth(Node *node) {
    if(!node)
        return 0;
    if(node->left==NULL && node->right==NULL)
        return 1;
    if(node->left && node->right)
        return 1+ min(minDepth(node->left),minDepth(node->right));
    else if(node->left)
        return 1+(minDepth(node->left));
    else
        return 1+(minDepth(node->right));
}

