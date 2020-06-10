/*You are given an array A of size N. You need to push the elements of the array into a stack and then print minimum in the stack at each pop.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains two lines of input. The first line of input contains size of array N. The second line of array contains the elements of array separated by spaces.

Output:
For each testcase, in a new line, print the required output.

Your Task:
Since this is a function problem, you don't need to take any input. Just complete the provided functions _push() and _getMinAtPop().

Constraints:
1 <= T <= 100
1 <= Ai <= 107

Examples:
Input:
2
5
1 2 3 4 5
7
1 6 43 1 2 0 5
Output:
1 1 1 1 1
0 0 1 1 1 1 1
*/
#include<bits/stdc++.h>
using namespace std;
stack<int>_push(int arr[],int n);
void _getMinAtPop(stack<int>s);
stack<int>_push(int arr[],int n)
{
   stack<int>s;
   for(int i=0;i<n;i++)
    s.push(arr[i]);
   return s;
}
void _getMinAtPop(stack<int>s){
    while(!s.empty()){
        int minn=INT_MAX,index=-1,i=0;
        stack<int> v=s;
        while(!v.empty()){
            if(v.top()<minn){
                minn=v.top();
                index=i;
            }
            i++;
            v.pop();
        }
        for(int j=0;j<=index;j++){
            cout<<minn<<" ";
            s.pop();
        }
    }
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
        stack<int> s=_push(a,n);
        _getMinAtPop(s);
        cout<<endl;
    }
    return 0;
}
