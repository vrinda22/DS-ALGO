/*Given an array arr[] of N nodes representing preorder traversal of BST. The task is to print its postorder traversal.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, the size of array. The second line of each test case contains N input as arr[i].

Output:
Postorder traversal of the given preorder traversal is printed.

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= arr[i] <= 104

Example:
Input:
3
5
40 30 35 80 100
8
40 30 32 35 80 90 100 120

Output:
35 30 100 80 40
35 32 30 120 100 90 80 40
*/
#include <bits/stdc++.h>
using namespace std;
void findPostOrderUtil(int pre[], int n, int minval,int maxval, int& preIndex)
{
	if (preIndex == n)
		return;
	if (pre[preIndex] < minval || pre[preIndex] > maxval) {
		return;
	}
	int val = pre[preIndex];
	preIndex++;
	findPostOrderUtil(pre, n, minval, val, preIndex);
	findPostOrderUtil(pre, n, val, maxval, preIndex);
	cout << val << " ";
}
void findPostOrder(int pre[], int n)
{
	int preIndex = 0;
	findPostOrderUtil(pre, n, INT_MIN, INT_MAX, preIndex);
}
int main()
{
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        findPostOrder(a, n);
        cout<<endl;
	}
        return 0;
}

