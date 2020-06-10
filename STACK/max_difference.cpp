/*Given array A[] of integers, the task is to complete the function findMaxDiff which finds the maximum absolute difference between nearest left and right smaller element of every element in array.If the element is the leftmost element, nearest smaller element on left side is considered as 0. Similarly if the element is the rightmost elements, smaller element on right side is considered as 0.

Examples:

Input : arr[] = {2, 1, 8}
Output : 1
Left smaller  LS[] {0, 0, 1}
Right smaller RS[] {1, 0, 0}
Maximum Diff of abs(LS[i] - RS[i]) = 1

Input  : arr[] = {2, 4, 8, 7, 7, 9, 3}
Output : 4
Left smaller   LS[] = {0, 2, 4, 4, 4, 7, 2}
Right smaller  RS[] = {0, 3, 7, 3, 3, 3, 0}
Maximum Diff of abs(LS[i] - RS[i]) = 7 - 3 = 4

Input : arr[] = {5, 1, 9, 2, 5, 1, 7}
Output : 1
Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow .Each test case contains an integer N denoting the size of the array A. In the next line are N space separated values of the array A.

Output:
For each test case output will be in a new line denoting the the maximum absolute difference between nearest left and right smaller element of every element in array.

Constraints:
1<=T<=100
1<=N<=100
1<=A[ ]<=100

Example(To be used only for expected output) :
Input:
2
3
2 1 8
7
2 4 8 7 7 9 3
Output
1
4
*/
#include<bits/stdc++.h>
using namespace std;
void leftsmaller(int a[],int n,int V[]){
    stack<int> s;
    for(int i=0;i<n;i++){
        while(!s.empty() && s.top()>=a[i])
            s.pop();
        if(!s.empty())
            V[i]=s.top();
        else
            V[i]=0;
        s.push(a[i]);
    }
}
int finddiff(int a[],int n){
    int LS[n];
    leftsmaller(a,n,LS);
    int RS[n];
    reverse(a,a+n);
    leftsmaller(a,n,RS);
    int result=-1;
    for(int i=0;i<n;i++)
        result=max(result,LS[i]-RS[n-i-1]);
    return result;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	int n;
   	cin>>n;
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	cout<<finddiff(a,n)<<endl;
   }
    return 0;
}

