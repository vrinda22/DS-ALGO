/*Compress the string when lower and upper case are same. In compressed string characters should be in lowercase.

for ex:     input    aaABBb

               output  3a3b

Input

The first line of the input contains a single integer T denoting the number of test cases.
The first line of each test case contains string s.
Output

For each test case, output the required string.

Constraints

    •    1 ≤ T ≤ 101

    •    1 ≤ |s|≤ 1000

Example

Input:

3

aabbB

abc

aaacca

Output:

2a3b

1a1b1c

3a2c1a
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
        transform(str.begin(),str.end(),str.begin(),::tolower);
        stack<int> s;
        for(int i=0;i<n;i++){
            if(str[i]==str[i+1])
                s.push(str[i]);
            else{
                cout<<s.size()+1<<str[i];
                while(!s.empty())
                    s.pop();
            }
        }
        cout<<endl;
    }
    return 0;
}
