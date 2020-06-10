/*Given an array arr[] and a number k. The task is to delete k elements which are smaller than next element (i.e., we delete arr[i] if arr[i] < arr[i+1]) or become smaller than next because next element is deleted.

Input:
The first line contains an integer T, the number of test cases. For each test case, the first line contains an integer n, denoting the size of the array. Next line contains n space separated integers, followed by an integer k, denoting the number of elements to be deleted from the array.

Output:
For each test case, the output is the array arr[] after deleting the k elements from the array if possible, else print the left array as it is.

Constraints:
1<=T<=100
2<=n<=100
1<=k<=100

Example:
Input
4
3
3 100 1
1
5
20 10 25 30 40
2
5
23 45 11 77 18
3
2
2 5
2
Output
100 1
25 30 40
77 18
5
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c,k;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++){
            cin>>c;
            v.push_back(c);
        }
        cin>>k;
        while(k--){
            vector<int>::iterator itr=v.begin();
            for(int i=1;i<v.size();i++){
                if(v[i]>v[i-1]){
                    v.erase(itr);
                    break;
                }
                else
                    itr++;
            }
        }
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }
    return 0;
}
