/*Given an expression string exp. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”

Input:
The first line of input contains an integer T denoting the number of test cases.  Each test case consists of a string of expression, in a separate line.

Output:
Print 'balanced' without quotes if the pair of parenthesis is balanced else print 'not balanced' in a separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ |s| ≤ 105

Example:
Input:
3
{([])}
()
([]

Output:
balanced
balanced
not balanced
*/
#include<bits/stdc++.h>
using namespace std;
bool check(string exp){
    stack<char> s;
    char x;
    for(int i=0;i<exp.length();i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            s.push(exp[i]);
            continue;
           }
           if(s.empty())
            return false;
        switch(exp[i]){
            case ')':
                x=s.top();
                s.pop();
                if(x=='{' || x=='[')
                    return false;
                break;
            case '}':
                x=s.top();
                s.pop();
                if(x=='(' || x=='[')
                    return false;
                break;
            case ']':
                x=s.top();
                s.pop();
                if(x=='{' || x=='(')
                    return false;
                break;
           }
    }
    return s.empty();
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        if(check(str))
            cout<<"Balanced"<<endl;
        else
            cout<<"Not Balanced"<<endl;
    }
    return 0;
}
