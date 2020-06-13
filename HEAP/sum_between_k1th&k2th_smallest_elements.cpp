/*Given an array of positive integers and two positive integers K1 and K2. Find sum of all elements greater tha K1th and smaller than K2th smallest elements of array.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N, denoting the length of the array. Next line contains N space seperated integers of the array. Third line contains two space seperated integers denoting K1th and K2th smallest elements.

Output:
For each test case, output the sum of all the elements between K1th and K2th smallest elements.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= K1, K2 <= 1014

Example:
Input
2
7
20 8 22 4 12 10 14
3 6
6
10 2 50 12 48 13
2 6

Output:
26
73
*/
#include<bits/stdc++.h>
using namespace std;
void swapp(int *a,int *b){
    int c=*a;
    *a=*b;
    *b=c;
}
void minheapify(int a[],int n,int index){
    int small=index;
    int l=2*index+1;
    int r=2*index+2;
    if(l<n && a[l]<a[small])
        small=l;
    if(r<n && a[r]<a[small])
        small=r;
    if(small!=index){
        swapp(&a[small],&a[index]);
        minheapify(a,n,small);
    }
}
int main(){
    int t,k1,k2;
    cin>>t;
    while(t--){
        int n,ans=0;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        cin>>k1>>k2;
        for(int i=(n/2)-1;i>=0;i--)
            minheapify(a,n,i);
        k1--;
        k2--;
        for(int i=0;i<=k1;i++){
            a[0]=a[n-1];
            n--;
            minheapify(a,n,0);
        }
        for(int i=k1+1;i<k2;i++){
            ans+=a[0];
            a[0]=a[n-1];
            n--;
            minheapify(a,n,0);
        }
        cout<<ans<<endl;
    }
    return 0;
}
