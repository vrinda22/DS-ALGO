/*Given a stack with push(), pop(), empty() operations, delete middle of it without using any additional data structure.
Middle: ceil(size_of_stack/2.0)

Input:
The first line contains an integer T, the number of test cases. For each test case, the first line contains an integer sizeOfStack denoting the stack size. Next line contains space separated integers that will be pushed into the stack.

Output:
For each test case, in a new line, print the stack elements. If stack size if 1 then just print the top element.

Your Task:
This is a function problem. The input is already taken by the driver code. You only need to complete the function deleteMid() that returns the modified stack.

Constraints:
1 <= T <= 100
1 <= sizeOfStack <= 100

Example:
Input:
3
5
1 2 3 4 5
7
1 2 3 4 5 6 7
4
1 2 3 4
Output:
5 4 2 1
7 6 5 3 2 1
4 3 1
*/
#include<bits/stdc++.h>
using namespace std;
stack<int> deleteMid(stack<int> s,int sizeofstack,int current){
    if(current==sizeofstack/2){
        s.pop();
        return s;
    }
    int v=s.top();
    s.pop();
    current++;
    stack<int> d=deleteMid(s,sizeofstack,current);
    d.push(v);
    return d;
}
int main() {
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        stack<int> myStack;
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);
        }
        if(sizeOfStack==1)
        {
            cout<<myStack.top();
        }
        else
        {
            stack<int> modified=deleteMid(myStack,myStack.size(),0);
            while(!modified.empty())
            {
                cout<<modified.top()<<" ";
                modified.pop();
            }
        }
        cout<<endl;
    }
	return 0;
}
