/*Given two binary max heaps as arrays, merge the given heaps, after merging the two arrays.
The task is very simple to merge the two arrays firstly keep all the elements of first array than elements second array, than apply the merge operation of heaps.

Input:
First line consists of T test cases. First line of every test case consists of 2 integers N and M, denoting the number elements of two arrays (MAX HEAP). Second and third line of every test cases consists of elements of 2 Heaps respectively.

Output:
Single line output, print the merged max heap.

Constraints:
1<=T<=100
1<=N,M<=100

Example:
Input:
1
4 3
10 5 6 2
12 7 9
Output:
12 10 9 2 5 7 6
*/
#include<bits/stdc++.h>
using namespace std;
void maxheapify(vector<int> &a,int index,int n){
    if(index>=n)
        return;
    int largest=index;
    int l=2*index+1;
    int r=2*index+2;
    if(l<n && a[l]>a[largest])
        largest=l;
    if(r<n && a[r]>a[largest])
        largest=r;
    if(largest!=index){
        swap(a[index],a[largest]);
        maxheapify(a,largest,n);
    }
}
void build(vector<int> &a,int n){
    for(int i=(n/2)-1;i>=0;i--)
        maxheapify(a,i,n);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> a;
        for(int i=0;i<n+m;i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        build(a,n+m);
        for(auto y:a)
            cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}
