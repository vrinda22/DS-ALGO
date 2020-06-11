/*Given an array of digits (values are from 0 to 9), find the minimum possible sum of two numbers formed from digits of the array. All digits of given array must be used to form the two numbers.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. First line of each test case contains an integer N denoting the size of the array. Next line of each test contains N space seperated integers denoting the elements of the array.
Output:

For each test case output a single line containing the required sum.
Constraints:

1<=T<=100
1<=N<=50
Example:

Input

2
6
6 8 4 5 2 3
5
5 3 0 7 4

Output

604
82
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        priority_queue<int,vector<int>,greater<int>> pq;
        int a,num1=0,num2=0;
        for(int i=0;i<n;i++){
            cin>>a;
            pq.push(a);
        }
        int tp;
        while(!pq.empty()){
            tp=pq.top();
            pq.pop();
            num1=num1*10+tp;
            if(!pq.empty()){
                tp=pq.top();
                pq.pop();
                num2=num2*10+tp;
            }
        }
        cout<<num1+num2<<endl;
    }
    return 0;
}
