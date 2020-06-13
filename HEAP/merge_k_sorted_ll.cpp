/*Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of linked lists N and next line contains data of nodes of all K linked lists, with first element as M, the length of linked list and next M elements for the same linked list.

Output:
For each testcase, in a new line, print the merged linked list.

Your Task:
The task is to complete the function mergeKList() which merges the K given lists into a sorted one. The printing is done automatically by the driver code.

Expected Time Complexity: O(nk Logk)
Expected Auxiliary Space: O(k)

Constraints
1 <= T <= 50
1 <= N <= 103

Example:
Input:
2
4
3 1 2 3 2 4 5 2 5 6 2 7 8
3
2 1 3 3 4 5 6 1 8
Output:
1 2 3 4 5 5 6 7 8
1 3 4 5 6 8
*/
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;

	Node(int x){
	    data = x;
	    next = NULL;
	}

};

Node* mergeKLists(Node* arr[], int N);

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}

   		Node *res = mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
Node *sortedmerge(Node *a,Node *b){
    Node *result=NULL;
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;
    if(a->data<=b->data){
        result=a;
        result->next=sortedmerge(a->next,b);
    }
    else{
        result=b;
        result->next=sortedmerge(a,b->next);
    }
    return result;
}
Node * mergeKLists(Node *arr[], int N)
{
    int last=N-1;
    while(last!=0){
        int i=0,j=last;
        while(i<j){
            arr[i]=sortedmerge(arr[i],arr[j]);
            i++;
            j--;
            if(i>=j)
                last=j;
        }
    }
    return arr[0];
}
