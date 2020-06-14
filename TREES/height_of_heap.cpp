/*Given a Binary Heap of size N, write a program to calculate the height of the Heap.

Input:
First line of the input contains an integer T, denoting the number of test cases. Then T test case follows. The first line of each test case contains an integer N denoting the number of node in the Heap. Next line contains N space separated integers denoting the elements of the heap.

Output:
For each test case print the height of the Heap on a new line.

Constraints:
1<=T<=100
1<=N<=103

Example:
Input:
2
6
1 3 6 5 9 8
9
3 6 9 2 15 10 14 5 12
Output:
2
3
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        cout<<ceil(log2(n+1)-1)<<endl;
    }
    return 0;
}
