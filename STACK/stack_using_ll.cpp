/*Let's give it a try! You have a linked list and you have to implement the functionalities push and pop of stack using this given linked list.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow. First line of each test case contains an integer Q denoting the number of queries.
A Query Q is of 2 Types
(i) 1 x   (a query of this type means  pushing 'x' into the stack)
(ii) 2     (a query of this type means to pop element from stack and print the poped element)
The second line of each test case contains Q queries seperated by space.

Output:
The output for each test case will  be space separated integers having -1 if the stack is empty else the element poped out from the stack .

Your Task:
You are required to complete the two methods push() which take one argument an integer 'x' to be pushed into the stack  and pop() which returns a integer poped out from the stack.

Constraints:
1 <= T <= 100
1 <= Q <= 100
1 <= x <= 100

Example:
Input:
2
5
1 2 1 3 2 1 4 2
4
2 1 4 1 5 2
Output:
3 4
-1 5
*/
#include <bits/stdc++.h>
using namespace std;

struct StackNode {
    int data;
    StackNode *next;
    StackNode(int a) {
        data = a;
        next = NULL;
    }
};

class MyStack {
  private:
    StackNode *top;

  public:
    void push(int);
    int pop();
    MyStack() { top = NULL; }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        MyStack *sq = new MyStack();

        int Q;
        cin >> Q;
        while (Q--) {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1) {
                int a;
                cin >> a;
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
    }
}
void MyStack::push(int x){
    StackNode *temp=new StackNode(x);
    if(top==nullptr)
        top=temp;
    else{
        temp->next=top;
        top=temp;
    }
}
int MyStack::pop(){
    int x=-1;
    if(top==nullptr)
        return x;
    else{
        x=top->data;
        top=top->next;
        return x;
    }
}

