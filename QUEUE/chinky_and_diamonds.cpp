/*One day Chinky was roaming around the park and suddenly she found N bags with diamonds.
The i'th of these bags contains Ai diamonds. She felt greedy and started to pick up the bag very fastly. But due to quick movement, she drops it on the ground. But as soon as she drops the bag, a genie appears in front of her and he increases the number of diamonds in the bag suddenly!
Now the bag which was used to contain P diamonds(before picking up), now contains [P/2] diamonds, where [p] is the greatest integer less than p. Then genie gave her the time K minutes in which she can take as many as diamonds. In a single minute , she can take all the diamonds in a single bag, regardless the number of diamonds in it. Find the maximum number of diamonds that Chinky can take with her.

Input:
First line contains an integer T. T test cases follow.First line of each test case contains two space-separated integers N and K.Second line of each test case contains N space-separated integers,the number of diamonds in the bags.

Output:
Print the answer to each test case in a new line.

Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 105
0 ≤ K ≤ 105
0 ≤ Ai ≤105

Example:
Input:
1
5 3
2 1 7 4 2
Output:
14
*/
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
