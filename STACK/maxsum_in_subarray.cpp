/*Given an array, find maximum sum of smallest and second smallest elements chosen from all possible sub-arrays. More formally, if we write all (nC2) sub-arrays of array of size >=2 and find the sum of smallest and second smallest, then our answer will be maximum sum among them.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the array. The next line contains N space separated values of the array.

Output:
For each test case in  a new line print an integer denoting the maximum sum of smallest and second smallest elements chosen from all possible subarrays.

Constraints:
1<=T<=103
2<=N<=103
1<=A[ ]<=1018

Example:
Input:
2
3
4 5 1
5
4 3 1 5 6
Output:
9
11
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        unsigned long long int max1,i,new1,old;
        cin>>old;
        cin>>new1;
        max1=new1+old;
        old=new1;
        for(i=2;i<n;i++){
            cin>>new1;
            max1=max(max1,new1+old);
            old=new1;
        }
        cout<<max1<<endl;
    }
    return 0;
}
