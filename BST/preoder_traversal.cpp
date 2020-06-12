/*Given an array arr of size n, write a program that prints 1 if given array can represent preorder traversal of a BST, else prints 0.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each testcase contains two lines of input.
The first line of each test case is n, denoting the size of array.
The second line of each test case contains n elements of the array.

Output:
For each testcase, in a new line, print 1 if the array represents preorder traversal else print 0.

Constraints:
1 <= T<= 100
1 <= n <= 103
1 <= arr[i] <= 103

Example:
Input:
3
5
40 30 35 80 100
8
40 30 32 35 80 90 100 120
8
7  9 6 1 4 2 3 40

Output:
1
1
0
*/
#include<bits/stdc++.h>
using namespace std;
bool answer(int pre[],int n){
    stack<int> s;
    int root=INT_MIN;
    for(int i=0;i<n;i++){
        if(pre[i]<root)
            return false;
        while(!s.empty() && s.top()<pre[i]){
            root=s.top();
            s.pop();
        }
        s.push(pre[i]);
    }
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
        if(answer(a,n))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0;
}
