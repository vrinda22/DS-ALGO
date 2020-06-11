/*Implement a Queue using Array. Your task is only to complete the functions push and pop.
Note: If at any point the queue is empty and you are asked to perform pop() operation, print -1.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer Q denoting the number of queries .
A Query Q is of 2 Types:
(i) 1 x   (a query of this type means  pushing 'x' into the queue)
(ii) 2     (a query of this type means to pop element from queue and print the poped element)
The second line of each test case contains Q queries seperated by space.

Output:
The output for each test case will  be space separated integers having -1 if the queue is empty else the element poped out from the queue .

Your Task :
You are required to complete the two methods push which take one argument an integer 'x' to be pushed into the quee  and pop which returns a integer poped out from othe queue.

Constraints:
1 <= T <= 100
1 <= Q <= 105
1 <= x <= 105

Example:
Input:
2
5
1 2 1 3 2 1 4 2
4
1 3 2 2 1 4
Output:
2 3
3 -1
*/
#include<bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
};

class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        MyQueue *sq = new MyQueue();

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
void MyQueue::push(int x){
    arr[rear]=x;
    rear++;
}
int MyQueue::pop(){
    if(front==rear){
        front=rear=0;
        return -1;
    }
    int a=arr[front];
    front++;
    return a;
}
