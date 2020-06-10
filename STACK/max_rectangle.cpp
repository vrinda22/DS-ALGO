/* Given a binary matrix, Your task is to complete the function maxArea which the maximum size rectangle area in a binary-sub-matrix with all 1’s. The function takes 3 arguments the first argument is the Matrix M[ ] [ ] and the next two are two  integers n and m which denotes the size of the matrix M. Your function should return an integer denoting the area of the maximum rectangle .

Input:
The first line of input is an integer T denoting the no of test cases . Then T test cases follow. The first line of each test case are 2 integers n and m denoting the size of the matrix M . Then in the next line are n*m space separated values of the matrix M.

Output:
For each test case output will be the area of the maximum rectangle .

Constraints:
1<=T<=100
1<=n,m<=1000
0<=M[][]<=1

Expected Time Complexity : O(n*m)
Expected Auixilliary Space : O(m)

Example:
Input
1
4 4
0 1 1 0 1 1 1 1 1 1 1 1 1 1 0 0

Output
8
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int maxhist(int a[],int n){
    stack<int> s;
    int i=0;
    int area,maxarea=INT_MIN;
    while(i<n){
        if(s.empty() || a[i]>=a[s.top()])
           s.push(i++);
        else{
            int top=s.top();
            s.pop();
            area=top*i;
            if(!s.empty())
                area=top*(i-s.top()-1);
            maxarea=max(area,maxarea);
        }
    }
    while(s.empty()==false){
        int top=s.top();
        s.pop();
        area=top*i;
        if(!s.empty())
           area=top*(i-s.top()-1);
        maxarea=max(area,maxarea);
    }
    return maxarea;
}
int area(int M[MAX][MAX],int n,int m){
    int maxx=maxhist(M[0],m);
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j])
                M[i][j]+=M[i-1][j];
        }
        maxx=max(maxx,maxhist(M[i],m));
    }
    return maxx;
}
int main(){
    int t;
    cin>>t;
    int M[MAX][MAX];
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>M[i][j];
        cout<<area(M,n,m)<<endl;
    }
    return 0;
}
