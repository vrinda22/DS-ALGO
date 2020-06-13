/*Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.

Input:
The first line of input contains the number of test cases, then T test cases follow. Each test case will contain an integer K denoting the number of sorted arrays(each with size K). Then in the next line contains all the elements of the array separated by space.

Output:
The output will be the sorted merged array.

User Task:
You need to complete mergeKArrays() function which takes 2 arguments, an arr[k][k] 2D Matrix containing k sorted arrays and an integer k denoting the number of sorted arrays. The function should return a pointer to the merged sorted arrays.

Expected Time Complexity: O(nk Logk)
Expected Auxiliary Space: O(k)
Note: This space is required for returning the resulted sorted array, other work should be done in O(K) Auxiliary Space.

Constraints:
1 <= T <= 50
1 <= K <= 100

Example:
Input:
2
3
1 2 3 4 5 6 7 8 9
4
1 2 3 4 2 2 3 4 5 5 6 6 7 8 9 9

Output:
1 2 3 4 5 6 7 8 9
1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9
*/
#include<bits/stdc++.h>
#define N 105
using namespace std;
int *mergeKArrays(int arr[][N],int k);
void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}
int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    int arr[N][N];
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	int *output = mergeKArrays(arr, k);
	printArray(output, k*k);
	cout<<endl;
}
	return 0;
}
int n;
struct MinHeapNode
{
	int element; // The element to be stored
	int i; // index of the array from which the element is taken
	int j; // index of the next element to be picked from array
};
void swap(MinHeapNode *x, MinHeapNode *y);
class MinHeap
{
	MinHeapNode *harr; // pointer to array of elements in heap
	int heap_size; // size of min heap
public:
	// Constructor: creates a min heap of given size
	MinHeap(MinHeapNode a[], int size);
	void MinHeapify(int );
	int left(int i) { return (2*i + 1); }
	int right(int i) { return (2*i + 2); }
	MinHeapNode getMin() { return harr[0]; }
	void replaceMin(MinHeapNode x) { harr[0] = x; MinHeapify(0); }
};
int *mergeKArrays(int arr[][N], int k)
{
    n =k;
	int *output = new int[n*k]; // To store output array
	MinHeapNode *harr = new MinHeapNode[k];
	for (int i = 0; i < k; i++)
	{
		harr[i].element = arr[i][0]; // Store the first element
		harr[i].i = i; // index of array
		harr[i].j = 1; // Index of next element to be stored from array
	}
	MinHeap hp(harr, k); // Create the heap
	for (int count = 0; count < n*k; count++)
	{
		MinHeapNode root = hp.getMin();
		output[count] = root.element;
		if (root.j < n)
		{
			root.element = arr[root.i][root.j];
			root.j += 1;
		}
		else root.element = INT_MAX; //INT_MAX is for infinite
		hp.replaceMin(root);
	}
	return output;
}
MinHeap::MinHeap(MinHeapNode a[], int size)
{
	heap_size = size;
	harr = a; // store address of array
	int i = (heap_size - 1)/2;
	while (i >= 0)
	{
		MinHeapify(i);
		i--;
	}
}
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l].element < harr[i].element)
		smallest = l;
	if (r < heap_size && harr[r].element < harr[smallest].element)
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}
void swap(MinHeapNode *x, MinHeapNode *y)
{
	MinHeapNode temp = *x; *x = *y; *y = temp;
}
