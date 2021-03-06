/*Given an expression exp of length n consisting of some brackets. The task is to print the bracket numbers when the expression is being parsed.

Input:
The first line contains an integer T, the number of test cases. For each test case, there is a string exp containing the expression.

Output:
For each test case, the output is the bracket numbers of the expression.

Constraints:
1<=T<=100
1<=S<=100

Example:
Input:
3​
(a+(b*c))+(d/e)​
((())(()))
((((()
Output:
1 2 2 1 3 3
1 2 3 3 2 4 5 5 4 1
1 2 3 4 5 5
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int n=str.length();
        stack<int> v;
        int open=0;
        for(int i=0;i<n;i++){
            if(str[i]=='('){
                open++;
                cout<<open<<" ";
                v.push(open);
               }
            else if(str[i]==')'){
                cout<<v.top()<<" ";
                v.pop();
               }
               else
                 continue;
        }
        cout<<endl;
    }
    return 0;
}
