/*Given a preorder traversal of a BST, print the leaf nodes of the tree without building the tree.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N denoting the no of nodes of the BST. Then in the next line are N space separated values denoting the preorder traversal of the binary tree.

Output:
For each test case in a new line print the leaf nodes separated by space of the BST in sorted order.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
5
890 325 290 530 965
3
3 2 4

Output:
290 530 965
2 4
*/
#include <iostream>
using namespace std;
void printleaf(int *arr,int l,int h)
{
    if(l>h)
    return;
    if(l==h)
    cout<<arr[l]<<" ";
    int i;
    for(i=l+1;i<=h;i++)
        if(arr[i]>arr[l])
        break;
    printleaf(arr,l+1,i-1);
    printleaf(arr,i,h);
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        int temp;
	        cin>>temp;
	        arr[i]=temp;

	    }
	    printleaf(arr,0,n-1);
	    cout<<endl;
	}
	return 0;
}
