/*The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stock’s price for all n days.
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, N is the size of the array. The second line of each test case contains N input C[i].

Output:
For each testcase, print the span values for all days.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 200
1 ≤ C[i] ≤ 800

Example:
Input:
2
7
100 80 60 70 60 75 85
6
10 4 5 90 120 80

Output:
1 1 1 2 1 4 6
1 1 2 4 5 1
*/
#include <bits/stdc++.h>
using namespace std;
void span(int price[],int n,int S[]){
    stack<int> v;
    v.push(0);
    S[0]=1;
    for(int i=1;i<n;i++){
        while(!v.empty() && price[i]>=price[v.top()])
            v.pop();
        S[i]=(v.empty())? (i+1) :(i-v.top());
        v.push(i);
    }
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int price[n],S[n];
        for(int i=0;i<n;i++)
            cin>>price[i];
        span(price,n,S);
        for(int i=0;i<n;i++)
            cout<<S[i]<<" ";
        cout<<endl;
    }
	//code
	return 0;
}
