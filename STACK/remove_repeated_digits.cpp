/*Given an integer N, remove consecutive repeated digits from it.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains the integer N.

Output:
Print the number after removing consecutive digits. Print the answer for each test case in a new line.


Constraints:
1<= T <=100
1<= N <=1018


Example:

Input:
1
12224

Output:
124
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        stack<long long int> s;
        while(n>0){
            s.push(n%10);
            n=n/10;
        }
        long long int tp=s.top();
        s.pop();
        while(!s.empty()){
            if(tp==s,top()){
                tp=s.top();
                s.pop();
                if(s.empty())
                    cout<<tp;
            }
            else{
                cout<<tp;
                tp=s.top();
                s.pop();
                if(s.empty())
                    cout<<tp;
            }
        }
        cout<<endl;
    }
    return 0;
}
