/*There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N where N is the number of ropes. The second line of each test case contains N input L[i],length of ropes.

Output:
For each testcase, print the minimum cost to connect all the ropes.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
1 ≤ L[i] ≤ 106

Example:
Input:
2
4
4 3 2 6
5
4 2 7 6 9

Output:
29
62
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a;
        cin>>n;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            cin>>a;
            pq.push(a);
        }
        long long int sum=0;
        int t1=0,t2=0;
        while(pq.size()!=1){
            t1=pq.top();
            pq.pop();
            t2=pq.top();
            pq.pop();
            sum+=t1+t2;
            pq.push(t1+t2);
        }
        cout<<sum<<endl;
    }
    return 0;
}
