/*Given a preOrder and inOrder traversal of a binary tree your task is to print the postOrder traversal of the tree .You are required to complete the function printPostOrder which prints the node of the tree in post order fashion . You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

Input Format:
The task is to complete the function printPostOrder which takes 3 argument, the first being the array of inOrder Traversal of the tree (in) , the second beeing the preOrder traversal of the tree (pre) and third being the no of nodes of the Tree (N).
There are multiple test cases. For each test case, this method will be called individually.

Output Format:
The function should print the PostOrder traversal of the binary tree separated by space.

Your Task:
Complete the function printPostOrder.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input
1
6
4 2 5 1 3 6
1 2 4 5 3 6
Output
4  5  2  6  3 1
*/
#include<bits/stdc++.h>
using namespace std;


void printPostOrder(int in[], int pre[], int n);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int pre[N],in[N];
        for(int i=0;i<N;i++)
            cin>>in[i];
        for(int i=0;i<N;i++)
            cin>>pre[i];
        printPostOrder(in,pre,N);
        cout<<endl;

    }
}
int searchh(int a[],int x,int n){
    for(int i=0;i<n;i++)
        if(a[i]==x)
            return i;
    return -1;
}
void printPostOrder(int in[], int pre[], int n)
{
    int root=searchh(in,pre[0],n);
    if(root!=0)
        printPostOrder(in,pre+1,root);
    if(root!=n-1)
        printPostOrder(in+root+1,pre+root+1,n-root-1);
    cout<<pre[0]<<" ";
}
