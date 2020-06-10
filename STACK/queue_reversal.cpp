/*Given a Queue Q containing N elements. The task is to reverse the Queue. Your task is to complete the function rev(), that reverses the N elements of the queue.

Input:
The first line of input contains an integer T denoting the Test cases. Then T test cases follow. The first line contains N which is the number of elements which will be reversed. Second line contains N space seperated elements.

Output:
For each testcase, in a new line, print the reversed queue.

Your Task:
This is a function problem. You only need to complete the function rev that takes a queue as parameter and returns the reversed queue. The printing is done automatically by the driver code.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 105
1 ≤ elements of Queue ≤ 105

Example:
Input :
2
6
4 3 1 10 2 6
4
4 3 2 1
Output :
6 2 10 1 3 4
1 2 3 4
*/
#include<bits/stdc++.h>
using namespace std;
queue<long long int> rev(queue<long long int> q){
    stack<long long int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    return q;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n,a;
        cin>>n;
        queue<long long int> q;
        for(int i=0;i<n;i++){
            cin>>a;
            q.push(a);
        }
        queue<long long int> v=rev(q);
        while(!v.empty()){
            cout<<v.front()<<" ";
            v.pop();
        }
        cout<<endl;
    }
    return 0;
}
