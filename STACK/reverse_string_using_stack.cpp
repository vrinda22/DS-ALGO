/*A string of words is given, the task is to reverse the string using stack.

Input Format:
The first line of input will contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains a string s of words without spaces.

Output Format:
For each test case ,print the reverse of the string in new line.

Your Task:
Since this is a function problem, you don't need to take any input. Just complete the provided function.

Constraints:
1 <= T <= 100
1 <= length of the string <= 100

Example:
Input:
2
GeeksQuiz
GeeksforGeeks
Output:
ziuQskeeG
skeeGrofskeeG
*/
#include<bits/stdc++.h>
using namespace std;
void rev(char *str,int len){
    stack<char> s;
    for(int i=0;i<len;i++)
        s.push(str[i]);
    for(int i=0;i<len;i++){
        str[i]=s.top();
        s.pop();
    }
}
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        rev(str,len);
        cout<<str;
        cout<<endl;
    }
        return 0;
}
