/*Your task is to implement  2 stacks in one array efficiently .

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer Q denoting the number of queries .
A Query Q is of 4 Types
(i)    1 1 x    (a query of this type means  pushing 'x' into the stack 1)
(ii)   1 2      (a query of this type means to pop element from stack1  and print the poped element)
(iii)  2 1 x  (a query of this type means pushing 'x' into the stack 2)
(iv)  2 2     (a query of this type means to pop element from stack2 and print the poped element)
The second line of each test case contains Q queries seperated by space.

Output:
The output for each test case will be space separated integers having -1 if the stack is empty else the element poped out from the stack.
You are required to complete the 4  methods push1, push2 which takes one argument an integer 'x' to be pushed into the stack one and two  and pop1, pop2 which returns a integer poped out from stack one and two .

Your Task:
Since this is a function problem, you don't need to take any input. Just complete the provided functions.

Constraints:
1 <= T <= 100
1 <= Q <= 100
1 <= x <= 100

Example:
Input
2
6
1 1 2 1 1 3 2 1 4 1 2 2 2 2 2
4
1 1 2 2 2 1 2 2 2
Output
3 4 -1
-1 2 -1
*/
#include<bits/stdc++.h>

using namespace std;

class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
public:
   twoStacks(int n=100){size = n; arr = new int[n]; top1 = -1; top2 = size;}

   void push1(int x);
   void push2(int x);
   int pop1();
   int pop2();
};



int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        twoStacks *sq = new twoStacks();

        int Q;
        cin>>Q;
        while(Q--){
        int stack_no;
        cin>>stack_no;
        int QueryType=0;
        cin>>QueryType;

        if(QueryType==1)
        {
            int a;
            cin>>a;
            if(stack_no ==1)
            sq->push1(a);
            else if(stack_no==2)
            sq->push2(a);
        }else if(QueryType==2){
        	if(stack_no==1)
            cout<<sq->pop1()<<" ";
            else if(stack_no==2)
            cout<<sq->pop2()<<" ";

        }
        }
        cout<<endl;
    }
}
void twoStacks::push1(int x){
    if(top1<top2-1){
        top1++;
        arr[top1]=x;
    }
}
void twoStacks::push2(int x){
    if(top1<top2-1){
        top2--;
        arr[top2]=x;
    }
}
int twoStacks::pop1(){
    if(top1>=0){
        int x=arr[top1];
        top1--;
        return x;
    }
    else
        return -1;
}
int twoStacks::pop2(){
    if(top2<size){
        int x=arr[top2];
        top2++;
        return x;
    }
    else
        return -1;
}
