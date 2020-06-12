/*Given a BST, modify it so that all greater values in the given BST are added to every node.

Input Format:

The first line of input contains the number of test cases T. Each test case contains a string representing the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.
Output:
Print the inorder traversal of the modified BST.

Your Task:
You don't need to read input or print anything. Your task is to complete the function modify() which takes one argument: root of the BST. The function should contain the logic to modify the BST so that in the modified BST, every node has a value equal to the sum of its value in the original BST and values of all the elements larger than it in the original BST. Return the root of the modified BST.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1<=T<=10
1<=N<=100000

Example:
Input:
2
50 30 70 20 40 60 80
2 1 5 N N 4 7

Output:
350 330 300 260 210 150 80
19 18 16 12 7
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



Node* modify(Node *root);

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

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s;
       getline(cin, s);
       Node* root = buildTree(s);

       //getline(cin, s);
        // int k = stoi(s);
        // getline(cin, s);

        root = modify(root);
        vector<int> v;
        inorder(root, v);
        for(auto i:v)
            cout << i << " ";
        cout << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}
void modifyroot(Node *root, int *sum){
    if(root==NULL)
        return;
    modifyroot(root->right,sum);
    *sum+=root->data;
    root->data=*sum;
    modifyroot(root->left,sum);
}
Node *modify(Node *root){
    int sum=0;
    modifyroot(root,&sum);
    return root;
}
