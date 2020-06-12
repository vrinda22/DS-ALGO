/*Given a BST and an integer K. Find the Kth Smallest element in the BST.

Input:
The first line of input contains the number of test cases T. For each test case, there will two lines. The first line of input is a string representing the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.
Second-line is an integer represents K

Output:
For each test case, the output will be the kth smallest element of BST. If no such element exists then print -1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function KthSmallestElement() which takes the root of the BST and integer K as inputs and return the Kth smallest element in the BST.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1<=T<=10
1<=N<=100000


Example(To be used only for expected output):
Input:
2
2 1 3
2
2 1 3
5
Output:
2
-1
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


int KthSmallestElement(Node *root, int k);

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

       getline(cin, s);
       int k = stoi(s);
      //  getline(cin, s);

       cout << KthSmallestElement(root, k) << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}
void store(Node *root,vector<int>&v){
    if(root==NULL)
        return;
    store(root->left,v);
    v.push_back(root->data);
    store(root->right,v);
}
int KthSmallestElement(Node *root, int K){
    vector<int> v;
    store(root,v);
    if(K<=v.size())
        return v[K-1];
    else
        return -1;
}

