/*You are given a Binary tree. You are required to find the number of pairs violating the BST property. In BST every element in left subtree must be less than every element in the right subtree. You are required to complete the function pairsViolatingBST(Node *root, int N).



Input:

The first line consists of an integer T denoting the number of test cases. Each test case consists of two lines. The first line of each test case consists of a single integer N, denoting the number of edges in the Binary tree. The next line contains the edges of the binary tree. Each edge consists of two integers and one character first of whose is parent node, second is child node and character "L" representing Left child and "R" representing the right child.


Output:

You are required to complete the function pairsViolatingBST(Node *root, int N) which takes the root of the tree and the number of edges N as the arguments. The function returns the required number of pairs. As the results can be large, return your result modulo 10^9 + 7

Constraints:

1 <= T <= 1000

1 <= N < 10^5



Example:

Input:

2

6

50 30 L 50 60 R 30 20 L 30 25 R 60 10 L 60 40 R

2

4 5 L 4 6 R

Output:

7

1

Explanation:

The binary tree for 1st test case is-

                  50

            /             \

      30                   60

    /     \                /      \

20       25         10       40

The pairs violating the BST property are: (20, 10), (25, 10), (30, 25), (30, 10), (50, 10), (50, 40), (60, 40). Hence, the result is 7.



The binary tree for 2nd test case is-

            4

     /              \

5                      6

The pair violating the BST property is: (5, 4). Hence, the result is 1.

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int indx,ans;

struct Node{
    int data;
    Node *left,*right;

    Node(int d){
        data=d;
        left=right=NULL;
    }
};
int pairsViolatingBST(Node *root,int n);
void insert(Node *root,int a,int b,char ch);

int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
		indx=0;
		ans=0;
        Node *root=NULL;
        for(int j=0;j<n;j++){
            int a,b;
            char ch;
            cin>>a>>b>>ch;
            if(root==NULL){
                root=new Node(a);
                switch(ch){
                    case 'L':root->left=new Node(b);
                            break;
                    case 'R':root->right=new Node(b);
                            break;
                }
            }else{
                insert(root,a,b,ch);
            }
        }
		cout<<pairsViolatingBST(root,n)<<"\n";
    }

	return 0;
}

void insert(Node *root,int a,int b,char ch){
    if(root==NULL)return;
    if(root->data==a){
        switch(ch){
            case 'L':root->left=new Node(b);
                    break;
            case 'R':root->right=new Node(b);
                    break;
        }
    }else{
        insert(root->left,a,b,ch);
        insert(root->right,a,b,ch);
    }
}
vector<int>v;
int countt(Node *root){
    if(!root)
        return 0;
    int res=0;
    res+=countt(root->left);
    for(auto it:v)
        if(it>root->data)
            res++;
    v.push_back(root->data);
    res+=countt(root->right);
    return res;
}
int pairsViolatingBST(Node *root,int n){
    v.clear();
    return countt(root);
}
