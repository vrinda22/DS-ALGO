/*Given an array A of size N, the task is to check if the given array represents a Binary Max Heap.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two lines. The first line of input contains an integer N denoting the size of the array. Then in the next line are N space separated array elements.

Output:
If array represents a Binary Max Heap, print "1", else print "0" (without quotes).

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1015

Example:
Input:
2
6
90 15 10 7 12 2
6
9 15 10 7 12 11

Output:
1
0
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
        bool isheap=true;
        for(int i=0;i<n;i++){
            if(a[(i-1)/2]<a[i]){
                isheap=false;
                break;
            }
        }
        cout<<isheap<<endl;
    }
    return 0;
}
