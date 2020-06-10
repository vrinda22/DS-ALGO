/*Given a postfix expression, the task is to evaluate the expression and print the final value. Operators will only include the basic arithmetic operators like *,/,+ and - .

Input:
The first line of input will contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains an postfix expression.

Output:
For each test case, in a new line, evaluate the postfix expression and print the value.

Constraints:
1 <= T <= 100
1 <= length of expression <= 100

Example:
Input:
2
231*+9-
123+*8-
Output:
-4
-3
*/
#include<bits/stdc++.h>
using namespace std;
int op(char c,int op1,int op2){
    switch(c){
        case '+': return op1+op2;
        case '-': return op1-op2;
        case '*': return op1*op2;
        case '/': return op1/op2;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int n=str.length();
        stack<int> s;
        for(int i=0;i<n;i++){
            if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/'){
                int op2=s.top();
                s.pop();
                int op1=s.top();
                s.pop();
                int result=op(str[i],op1,op2);
                s.push(result);
            }
            else
                s.push(str[i]-'0');
        }
        cout<<s.top()<<endl;
    }
    return 0;
}
