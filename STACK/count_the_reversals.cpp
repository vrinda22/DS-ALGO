/*Given a string S consisting only of opening and closing curly brackets '{' and '}' find out the minimum number of reversals required to make a balanced expression.

Input
The first line of input contains an integer T, denoting the number of test cases. Then T test cases
follow. The first line of each test case contains a string S consisting only of { and }.

Output
Print out minimum reversals required to make S balanced. If it cannot be balanced, then print -1.

Constraints
1 <= T <= 100
0 <= |S| <= 50

Examples
Input
4
}{{}}{{{
{{}}}}
{{}{{{}{{}}{{
{{{{}}}}

Output
3
1
-1
0
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
        if(n%2==1)
            cout<<"-1"<<endl;
        else{
            int l=0,c=0;
            for(int i=0;i<n;i++){
                if(str[i]=='{')
                    l++;
                if(str[i]=='}')
                    l--;
                if(l<0){
                    l=1;
                    c++;
                }
            }
            c=c+l/2;
            cout<<c;
        }
        cout<<endl;
    }
    return 0;
}
