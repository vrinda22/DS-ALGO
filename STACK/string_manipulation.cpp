/*Tom is a string freak. He has got sequences of  n words to manipulate. If in a sequence, two same words come together then he’ll destroy each other. He wants to know the number of words left in the sequence after this pairwise destruction.


Input:
The first line of input contains an integer denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of input contains an integer n denoting the number of words in a sequence. In the second line are n space separated words of the sequence. Words are contiguous stretches of printable characters delimited by white space.


Output:
For each test case in a new line print the number of words left per sequence.


Constraints:
1<=T<=100
1<=n<=100


Example:
Input:
2
5
ab aa aa bcd ab
4
tom jerry jerry tom

Output:
3
0
*/
#include<bits/stdc++.h>
using namespace std;
void check(string str[],int n){
    stack<string>s;
    for(int i=0;i<n;i++){
        if(s.empty() || str[i].compare(s.top())!=0)
            s.push(str[i]);
        else
            s.pop();
    }
    cout<<s.size()<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string str[n];
        for(int i=0;i<n;i++)
            cin>>str[i];
        check(str,n);
    }
    return 0;
}
