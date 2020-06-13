/*Given an array arr[] and an integer K, you have to Add first two minimum elements of the array until all the elements are greater than K and find the number of such operations required.

Examples:

Input : arr[] = {1 10 12 9 2 3}
          K = 6
Output : 2
First we add (1 + 2), now the new list becomes
3 10 12 9 3, then we add (3 + 3),  now the new
list becomes 6 10 12 9, Now all the elements in
the list are greater than 6. Hence the output is
2 i:e 2 operations are required
to do this.
Input :  The first line of input contains an integer T denoting the Test cases. Then T test cases follow.  Second line contains no. of array elements - N and K Third line array elements A[i]

Output :
Print number of operations required. If it is not possible to make elements greater than or equal to K, print "-1".

Constraints :
1 ≤ T ≤ 50
1 ≤ N, K ≤ 10^5
1 ≤ A[i] ≤ 10^6

Input :
2
6 6
1 10 12 9 2 3
5 15
1 2 1 2 2
Output :
2
-1
*/
#include<bits/stdc++.h>
using namespace std;
class MinHeap
{
	int *harr;
	int capacity; // maximum size
	int heap_size; // Current count
public:
	MinHeap(int *arr, int capacity);
	void heapify(int );
	int parent(int i)
	{
		return (i-1)/2;
	}
	int left(int i)
	{
		return (2*i + 1);
	}
	int right(int i)
	{
		return (2*i + 2);
	}
	int extractMin();
	int getMin()
	{
		return harr[0];
	}
	int getSize()
	{
		return heap_size;
	}
	void insertKey(int k);
};
MinHeap::MinHeap(int arr[], int n)
{
	heap_size = n;
	capacity = n;
	harr = new int[n];
	for (int i=0; i<n; i++)
		harr[i] = arr[i];
	for (int i=n/2-1; i>=0; i--)
		heapify(i);
}
void MinHeap::insertKey(int k)
{
	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;
	while (i != 0 && harr[parent(i)] > harr[i])
	{
		swap(harr[i], harr[parent(i)]);
		i = parent(i);
	}
}
int MinHeap::extractMin()
{
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}
	int root = harr[0];
	harr[0] = harr[heap_size-1];
	heap_size--;
	heapify(0);
	return root;
}

void MinHeap::heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(harr[i], harr[smallest]);
		heapify(smallest);
	}
}
int countMinOps(int arr[], int n, int k)
{
	MinHeap h(arr, n);
	long int res = 0;
	while (h.getMin() < k)
	{
		if (h.getSize() == 1)
			return -1;
		int first = h.extractMin();
		int second = h.extractMin();
		h.insertKey(first + second);

		res++;
	}
	return res;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        cout<<countMinOps(a,n,k)<<endl;
    }
    return 0;
}
