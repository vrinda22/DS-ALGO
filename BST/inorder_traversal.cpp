/*Given an array, write a program that prints 1 if array represents Inorder traversal of a BST, else prints 0. Note that all keys in BST must be unique.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, N is the size of array. The second line of each test case contains N input C[i].

Output:
Print 1 array represents BST, else 0.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 500
1 ≤ Keys in BST ≤ 1200

Example:
Input
3
5
10 20 30 40 50
6
90 80 100 70 40 30
3
1 1 2

Output
1
0
0
*/
#include<bits/stdc++.h>
using namespace std;
bool sorted(int a[],int n){
    if(n==1 || n==0)
        return true;
    for(int i=1;i<n;i++)
        if(a[i-1]>=a[i])
        return false;
    return true;
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
        bool v=sorted(a,n);
        if(v)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}
