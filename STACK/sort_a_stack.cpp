/*Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Input:
The first line of input will contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains an integer N denoting the size of the stack. Then in the next line are N space separated values which are pushed to the the stack.

Output:
For each test case output will be the popped elements from the sorted stack.

Constraints:
1<=T<=100
1<=N<=100

Expected Time Complexity : O(n)
Expected Auixilliary Space : O(n)

Example(To be used only for expected output):
Input:
2
3
3 2 1
5
11 2 32 3 41

Output:
3 2 1
41 32 11 3 2
*/
#include<bits/stdc++.h>
using namespace std;
class SortedStack{
public:
	stack<int> s;
	void sortt();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sortt();
	printStack(ss->s);
}
}
void SortedStack :: sortt(){
    stack<int> temp;
    while(!s.empty()){
        int t=s.top();
        s.pop();
        while(!temp.empty() && temp.top()<t){
            s.push(temp.top());
            temp.pop();
        }
        temp.push(t);
    }
    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }
}
