/*Given a Binary Search Tree and two node values x and y present in the BST. Your task is to find the pth (p >= 1) common ancestor of these two nodes x and y.

The 1st common ancestor is the lowest common ancestor. The lowest common ancestor between two nodes n1 and n2 is defined as the lowest node in T that has both n1 and n2 as descendants (where we allow a node to be a descendant of itself).

All the elements of BST are non-negative and there is no duplicate entry in BST. Also, x and y are unequal.

You are required to complete the function pthCommonAncestor().

Return -1 if the pth common ancestor doesn’t exist for a given BST.

Note: The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.


Input:

The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consists of three lines. The first line of each test case consists of two integers N and p, denoting the number of elements in the BST and the pth common ancestor to be found, respectively. The second line of each test case consists of N space-separated integers denoting the elements in the BST. The third line of each test case consists of two integers x and y as described in the problem statement.


Output:

You are required to complete the function pthCommonAncestor() which takes the root of the tree and two integers x and y(as described in the problem statement) as the arguments. The function returns the value of pth common ancestor to be found.



Constraints:



1 <= T <= 1000

2 <= N <= 1000

1 <= p <= 100


Example:

Input:

2

6 2

50 30 70 60 55 65

55 65

5 2

6 3 8 1 4

1 4

Output:

70

6
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

struct NODE
{
	int data;
	struct NODE *left;
	struct NODE *right;

	NODE(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

NODE *root=NULL;

NODE* insert(int num,NODE *root);
int pthCommonAncestor(int x,int y,NODE *root,int p,vector<int> &vec);

int main()
{
    int t,n,num,x,y,temp,p;
    scanf("%d",&t);
	while(t--){
		vector<int> vec;
	    NODE *root = NULL;
		vec.clear();
		scanf("%d %d",&n,&p);
		while(n--){
			scanf("%d",&num);
			root=insert(num,root);
		}
		scanf("%d%d",&x,&y);
		if(x>y){
			temp=x;
			x=y;
			y=temp;
		}
		printf("%d\n",pthCommonAncestor(x,y,root,p,vec));
	}
    return 0;
}

NODE *insert(int num,NODE *root){
	if(root==NULL){
		NODE *temp=new NODE(num);
		return temp;
	}else if(root->data>=num)root->left=insert(num,root->left);
	else root->right=insert(num,root->right);
	return root;
}
int pthCommonAncestor(int x,int y,NODE *root,int p,vector<int> &vec){
    if(root->data<x && root->data<y)
       {
           vec.push_back(root->data);
           return pthCommonAncestor(x,y,root->right,p,vec);
       }

      else if(root->data>x && root->data>y)
       {
           vec.push_back(root->data);
           return  pthCommonAncestor(x,y,root->left,p,vec);
       }

      else
          {
              vec.push_back(root->data);
              if(p>vec.size())
               return -1;
              else
              return vec[vec.size()-p];
          }
}
