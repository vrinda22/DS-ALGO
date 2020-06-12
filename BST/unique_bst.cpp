/*Given an integer N, how many structurally unique binary search trees are there that store values 1...N?

Input:
First line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains a single line of input containing N.

Ouput:
For each testcase, in a new line, print the answer.

Constraints:
1<=T<=15
1<=N<=11

Example:
Input:
2
2
3
Output:
2
5
*/
#include <bits/stdc++.h>
using namespace std;

int numTrees(int n) {
    int i,j,k,A[n+1];
    A[0]=1;
    A[1]=1;
    for(i=2;i<=n;i++){
        A[i]=0;
        for(j=1;j<=i;j++){
            A[i]=A[i]+A[j-1]*A[i-j];
        }
    }
    return A[n];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<numTrees(n)<<"\n";
    }
}
