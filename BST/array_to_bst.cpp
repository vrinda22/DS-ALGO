/*Given a sorted array. Write a program that creates a Balanced Binary Search Tree using array elements. If there are N elements in array, then floor(n/2)'th element should be chosen as root and same should be followed recursively.

Input:
The first line of input contains an integer T, denoting the number of test cases. The first line of each test case is N(size of array). The second line of each test case contains N input A[].

Output:
Print the preorder traversal of constructed BST.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 1000
1 ≤ A[i] ≤ 10000

Example:
Input:
1
7
1 2 3 4 5 6 7

Output:
4 2 1 3 6 5 7
*/
#include<bits/stdc++.h>
using namespace std;
void cal(int a[],int low,int high){
    if(low>high)
        return;
    int mid=(low+high)/2;
    cout<<a[mid]<<" ";
    cal(a,low,mid-1);
    cal(a,mid+1,high);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        cal(a,0,n-1);
        cout<<endl;
    }
    return 0;
}
