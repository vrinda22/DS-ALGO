/*Given a Binary Tree of size N and an integer K. Print all nodes that are at distance k from root (root is considered at distance 0 from itself). Nodes should be printed from left to right. If k is more that height of tree, nothing should be printed.

For example, if below is given tree and k is 2. Output should be 4 5 6.

          1
       /     \
     2        3
   /         /   \
  4        5    6
     \
      8

Input:
First line of input contains the number of test cases T. For each test case, there will be only two line of input , first line contains integer value K and second line contains a string representing the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
The function should print nodes at K distance from root. Nodes should be printed from left to right. If their is no node at distance K you don't need to print anything.

Your Task:
You don't have to take input. Complete the function printKdistance() that accepts root node and k as parameter and print the value of the nodes that are at a distance k from the root. The new line will be printed by driver code only, you don't need to print a new line.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= T <= 100
1 <= N <= 104
0 <= K <= 30

Example:
Input:
2
0
1 3 2
3
3 2 N N 1 5 3
Output:
1
5 3
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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

void printKdistance(struct Node *root, int k);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k;
		scanf("%d ",&k);
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        printKdistance(root, k);
        cout<<endl;
    }
    return 1;
}
void printKdistance(struct Node *root, int k)
{
  if(!root)
    return;
  if(k==0){
    cout<<root->data<<" ";
    return;
  }
  printKdistance(root->left,k-1);
  printKdistance(root->right,k-1);
}
