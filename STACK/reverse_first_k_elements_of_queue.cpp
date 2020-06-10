/*Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Input:
First line consists of T test cases. First line of every test case consists of 2 integers, N and K, denoting number of elements and number of elements to be reversed respectively. Second line of every test case consists of elements of array.

Output:
For each testcase, in a new line, print the modified queue.

Your Task:
Since this is a function problem, you don't need to take inputs. Just complete the provided function modifyQueue that takes queue and k as parameters and returns a modified queue. The printing is done automatically by the driver code.

Expected TIme Complexity : O(n)
Expected Auxilliary Space : O(n)

Constraints:
1 <= T <= 100
1 <= N <= 1000
1 <= K <= N

Example:
Input:
2
5 3
1 2 3 4 5
4 4
4 3 2 1
Output:
3 2 1 4 5
1 2 3 4
*/
#include<bits/stdc++.h>
using namespace std;
queue<long long int> modify(queue<long long int> q,int k){
    stack<long long int> s;
    queue<long long int> temp;
    for(int i=0;i<k && !q.empty();i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        temp.push(s.top());
        s.pop();
    }
    while(!q.empty()){
        temp.push(q.front());
        q.pop();
    }
    return temp;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n,a,k;
        cin>>n>>k;
        queue<long long int> q;
        for(int i=0;i<n;i++){
            cin>>a;
            q.push(a);
        }
        queue<long long int> v=modify(q,k);
        while(!v.empty()){
            cout<<v.front()<<" ";
            v.pop();
        }
        cout<<endl;
    }
    return 0;
}
