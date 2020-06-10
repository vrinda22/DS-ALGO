/*Given a sorted deck of cards numbered 1 to N.

1) We pick up 1 card and put it on the back of the deck.

2) Now, we pick up another card , it turns out to be card numbered 1 , we put it outside the deck.

3) Now we pick up 2 cards and put it on the back of the deck.

4) Now, we pick up another card and it turns out to be card numbered 2 , we put it outside the deck. ...

We perform this step till the last card.

If such arrangement of decks is possible, output the arrangement, if it is not possible for a particular value of N then output -1.

Input:
The first line of the input contains the number of test cases 'T', after that 'T' test cases follow.
Each line of the test case consists of a single linecontaining an integer 'N'.


Output:
If such arrangement of decks is possible, output the arrangement, if it is not possible for a particular value of n then output -1.

Constraints:
1 <= T <= 100;
1<= N<= 1000;


Example:

Input :
2
4
5

Output :
2 1 4 3
3 1 4 5 2
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
//code
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        queue<int> q;
        int arr[n];
        memset(arr,0,n);
        for(int i=1;i<=n;++i){
            q.push(i);
        }
        int num=1;
        int count=1;
        while(!q.empty()){
            for(int i=0;i<count;++i){
                int x=q.front();
                q.pop();
                q.push(x);
            }
            arr[q.front()-1]=num;
            q.pop();
            num++;
            count++;
        }
        for(int i=0;i<n;++i){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
    }
