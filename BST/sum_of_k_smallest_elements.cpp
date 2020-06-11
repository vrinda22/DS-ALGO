/*Given Binary Search Tree. The task is to find sum of all elements smaller than and equal to Kth smallest element.
Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consists of three lines.
First line of each test case consist of integer N, denoting the number of elements in a BST.
Second line of each test case consists of N space separated integers denoting the elements in the BST. (ignore duplicate during insertion in bst)
Third line of each test case consists of an integer K, denoting the Kth smallest elements.

Output:
It should be single line output, Print the respective output in the respective line.

Constraints:
1<=T<=100
1<=N<=50
1<=K<=N

Example:
Input:
1
7
20 8 4 12 10 14 22
3
Output:
22
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,int>m;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            m[temp]++;
        }
        int k,sum=0;
        cin>>k;
        map<int,int>::iterator it;
        it=m.begin();
        while(k--){
            sum+=it->first;
            it++;
        }
        cout<<sum<<endl;
    }
    return 0;
}
