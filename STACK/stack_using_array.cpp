/*Implement a Stack using Array. Your task is to complete the functions below.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer Q denoting the number of queries .
A Query Q is of 2 Types:
(i) 1 x   (a query of this type means  pushing 'x' into the stack)
(ii) 2     (a query of this type means to pop element from stack and print the poped element)
The second line of each test case contains Q queries seperated by space.

Output:
The output for each test case will  be space separated integers having -1 if the stack is empty else the element poped out from the stack .

Your Task:
You are required to complete two methods push which take one argument an integer 'x' to be pushed into the stack  and pop which returns a integer poped out from the stack.

Expected Time Complexity : O(n)
Expected Auixilliary Space : O(n)

Constraints:
1 <= T <= 100
1 <= Q <= 100
1 <= x <= 100

Example:
Input:
4
5
1 2 1 3 2 1 4 2
4
2 1 4 1 5 2
20
2 2 1 40 2 1 68 2 1 28 1 85 1 21 1 23 2 1 82 1 85 1 73 1 51 2 2 1 100 1 43 1 14
9
1 43 1 97 2 1 12 1 16 2 1 33 1 51 2
Output:
3 4
-1 5
-1 -1 40 68 23 51 73
97 16 51
*/
#include<bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};


int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        MyStack *sq = new MyStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }
}
void MyStack::push(int x){
    if(top<1000)
        arr[++top]=x;
}
int MyStack::pop(){
    if(top<0)
        return -1;
    else
        return arr[top--];
}
