#include<bits/stdc++.h>
using namespace std;
int sum(int a[],int n,int k){
    if(n<k){
        cout<<"Invalid"<<endl;
        return -1;
    }
    int sum=0;
    for(int i=0;i<k;i++)
        sum+=a[i];
    int windowsum=sum;
    for(int i=k;i<n;i++){
        windowsum+=a[i]-a[i-k];
        sum=max(sum,windowsum);
    }
    return sum;
}
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<sum(a,n,k)<<endl;
    return 0;
}
