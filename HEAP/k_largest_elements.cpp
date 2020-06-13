/*Given an array of N positive integers, print k largest elements from the array.  The output elements should be printed in decreasing order.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N and k, N is the size of array and K is the largest elements to be returned. The second line of each test case contains N input C[i].

Output:
Print the k largest element in descending order.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100
K ≤ N
1 ≤ C[i] ≤ 1000

Example:
Input:
2
5 2
12 5 787 1 23
7 3
1 23 12 9 30 2 50

Output:
787 23
50 30 23
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            int c;
            cin>>c;
            pq.push(c);
        }
        while(k--){
            cout<<pq.top()<<" ";
            pq.pop();
        }
        cout<<endl;
    }
    return 0;
}
