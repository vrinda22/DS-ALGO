#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,j;
        cin>>n>>k;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            cin>>j;
            pq.push(j);
        }
        int sum=0;
        while(k--){
            j=pq.top();
            pq.pop();
            sum+=j;
            pq.push(j/2);
        }
        cout<<sum<<endl;
    }
    return 0;
}
