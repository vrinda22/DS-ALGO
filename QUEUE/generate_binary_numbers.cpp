/*Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N.

Input:
The first line of input contains an integer T denoting the number of test cases. There will be a single line for each testcase which contains N.

Output:
Print all binary numbers with decimal values from 1 to N in a single line.

Constraints:
1 ≤ T ≤ 106
1 ≤ N ≤ 106

Example:
Input:
2
2
5

Output:
1 10
1 10 11 100 101
*/
#include<bits/stdc++.h>
using namespace std;
void print(int n){
    queue<string> q;
    q.push("1");
    for(int i=1;i<=n;i++){
        string v= q.front();
        q.pop();
        cout<<v<<" ";
        q.push(v+"0");
        q.push(v+"1");
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        print(n);
        cout<<endl;
    }
    return 0;
}
