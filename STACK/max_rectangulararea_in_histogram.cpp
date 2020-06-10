/*Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have same width and the width is 1 unit.

Input:
The first line contains an integer 'T' denoting the total number of test cases. T test-cases follow. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array. The elements of the array represents the height of the bars.

Output:
For each test-case, in a separate line, the maximum rectangular area possible from the contiguous bars.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= A[i] <= 1018

Example:
Input:
2
7
6 2 5 4 5 1 6
4
6 3 4 2
Output:
12
9
*/
#include <bits/stdc++.h>
#include <fstream>
#include <ctime>
#include <chrono>


using namespace std;
long long arr[10000000];
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        for(long long i=0;i<n;i++)
        cin>>arr[i];
        long long max_area=-1;
        stack<long long>s;
        long long i=0;
        while(i<n)
        {
            if(s.empty()||arr[s.top()]<=arr[i])
            {
                s.push(i++);
            }
            else
            {
                long long top_index=s.top();
                s.pop();
                long long currarea=arr[top_index]*(s.empty()?i:i-1-s.top());
                if(currarea>max_area)
                max_area=currarea;
            }
        }
        while(!s.empty())
        {
            long long top_index=s.top();
            s.pop();
            long long currarea=arr[top_index]*(s.empty()?i:i-1-s.top());
            if(currarea>max_area)
            max_area=currarea;
    }
    cout<<max_area<<endl;
    }
	return 0;
}
