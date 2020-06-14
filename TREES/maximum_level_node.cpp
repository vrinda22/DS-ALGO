/*Given a Binary tree. Find the level in binary tree which has the maximum number of nodes.

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
Print the level number with maximum nodes.
Your Task:
You don't need to read input or print anything. Your task is to complete the function maxNodeLevel() that takes root node of the tree as input and returns an integer which is level of the tree with maximum nodes. The root is at level 0. If two or more levels have same number of maximum nodes , then print smallest level.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1<=T<=50
1<=N<=105
Example:
Input:
2
2 1 3 4 6 N 8 N N 5
1 2
Output:
2
0
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

int maxNodeLevel(Node *root);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        int ans = maxNodeLevel(root);
        cout<<ans<<endl;
    }
    return 1;
}
void solve(Node *root,map<int,int>&m,int hd){
    if(!root)
        return;
    m[hd]++;
    solve(root->left,m,hd+1);
    solve(root->right,m,hd+1);
}
int maxNodeLevel(Node *root)
{
    map<int,int> m;
    solve(root,m,0);
    int ans=0,ma=INT_MIN;
    for(auto it=m.begin();it!=m.end();it++)
    if(ma<it->second){
        ans=it->first;
        ma=it->second;
    }
    return ans;
}
