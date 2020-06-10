/*Gotham has been attacked by Joker . Bruce Wayne has deployed automatic machine gun at each tower of Gotham.
All the towers in Gotham are in straight line.
You are given no of towers 'n' followed by height of 'n' towers.
For every tower(p), find the height of the closest tower (towards the right), greater than the height of tower(p).
Now , Print sum of all such heights (mod 1000000001).

Note : If for a tower(k) , no such tower exsits then take its height as 0.

Input:
First line of the input contains t, the number of test cases. First line of each test case contains 'n' denoting no of towers.
This is followed by 'n' spaced integers h1,h2.....h(n) representing height of towers.

Output:
On a single line, output the sum(mod 1000000001).


Constraints:
1<=t<=100
1<=n<=18000
0<=a[i]<=100000


Example:

Input:
1
9
112 133 161 311 122 512 1212 0 19212


Output:
41265
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        stack<int> s;
        s.push(0);
        int sum=0;
        for(int i=n-1;i>0;i--){
            if(a[i]>a[i-1]){
                s.push(a[i]);
                sum+=a[i];
            }
            else{
                while(!s.empty()){
                    if(s.top()>a[i-1]){
                        s.push(s.top());
                        sum+=s.top();
                        break;
                    }
                    else
                        s.pop();
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
