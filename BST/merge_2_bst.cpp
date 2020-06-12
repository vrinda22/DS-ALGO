/*Given two BST, Return elements of both BSTs in sorted form.

Input Format:
The first line of input contains the number of test cases T. For each test case, there will be two lines of input. First of which is a string representing the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.
Second-line is a string which represents a BST in the same format as described above.

Output Format:
For each test case, in a new line, print the elements of both BSTs in sorted form.

Your Task:
You don't need to read input or print anything. Your task is to complete the function merge() which takes roots of both the BSTs as its input and returns an array of integers denoting the node values of both the BSTs in a sorted order.

Expected Time Complexity: O(M+N) where M and N are the sizes if the two BSTs.
Expected Auxiliary Space: O(Height of BST1 + Height of BST2).

Constraints:
1 <= T <= 10
1 <= Number of Nodes <= 100000

Example:
Input:
2
5 3 6 2 4
2 1 3 N N N 7 6
12 9 N 6 11
8 5 10 2

Output:
1 2 2 3 3 4 5 6 6 7
2 5 6 8 9 10 11 12
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
vector<int> mergee(Node *root1,Node *root2);
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
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);

       // getline(cin, s);

       vector<int> vec = mergee(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
void inorder(Node *root, vector<int> &ans)
{
    if(root==NULL)
        return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
Node *minValueNode(Node *nod)
{
    Node *current = nod;
    while(current->left !=NULL)
        current = current->left;
    return current;
}
vector<int> mergee(Node *root1,Node *root2){
    stack<Node *> s1;
    stack<Node *> s2;
    Node *c1 = root1;
    Node *c2 = root2;

    vector<int> ans;
    if(root1==NULL)
    {
        inorder(root2, ans);
        return ans;
    }
    if(root2==NULL)
    {
        inorder(root1, ans);
        return ans;
    }
    while(c1!=NULL or !s1.empty() or c2!=NULL or !s2.empty())
    {
        if(c1!=NULL or c2!=NULL)
        {
            if(c1!=NULL)
            {
                s1.push(c1);
                c1 = c1->left;
            }
            if(c2!=NULL)
            {
                s2.push(c2);
                c2 = c2->left;
            }
        }
        else
        {
            if(s1.empty())
            {
                while(!s2.empty())
                {
                    c2  = s2.top();
                    s2.pop();
                    c2->left= NULL;
                    inorder(c2, ans);
                }
                return ans;
            }
            if(s2.empty())
            {
                while(!s1.empty())
                {
                    c1  = s1.top();
                    s1.pop();
                    c1->left = NULL;
                    inorder(c1, ans);
                }
                return ans;
            }
            c1 = s1.top();
            c2  = s2.top();
            s1.pop();
            s2.pop();
            if(c1->data < c2->data)
            {
                ans.push_back(c1->data);
                c1 = c1->right;
                s2.push(c2);
                c2 = NULL;
            }else
            {
                ans.push_back(c2->data);
                c2 = c2->right;
                s1.push(c1);
                c1 = NULL;
            }
        }
    }
    return ans;
}
