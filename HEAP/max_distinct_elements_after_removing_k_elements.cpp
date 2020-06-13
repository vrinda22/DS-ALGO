/*Given an array containing N elements. The task is to find maximum number of distinct elements after removing K elements from the array.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains two Integers N and K and the second line contains N space separated elements.

Output:
For each test case, print the maximum distinct elements after removing K elements in new line.

Constraints:
1<=T<=100
1<=K<=N<=106
1<=A[i]<=105

Example:
Input:
2
7 3
5 7 5 5 1 2 2
7 5
1 2 3 4 5 6 7
Output:
4
2
*/
#include<bits/stdc++.h>
using namespace std;
int answer(int a[],int n,int k){
    unordered_map<int,int> mp;
    priority_queue<int> pq;
    for(int i=0;i<n;i++)
        mp[a[i]]++;
    for(auto it=mp.begin();it!=mp.end();it++)
        pq.push(it->second);
    while(k--){
        int temp=pq.top();
        pq.pop();
        temp--;
        if(temp!=0)
            pq.push(temp);
    }
    int res=0;
    while(pq.empty()==false){
        int x=pq.top();
        pq.pop();
        if(x==1)
            res++;
    }
    return res;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
    int ans=answer(a,n,k);
    cout<<ans<<endl;
    }
    return 0;
}
