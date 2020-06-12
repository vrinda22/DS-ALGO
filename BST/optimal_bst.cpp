/*Given a sorted array keys[0.. n-1] of search keys and an array freq[0.. n-1] of frequency counts, where freq[i] is the number of searches to keys[i]. Construct a binary search tree of all keys such that the total cost of all the searches is as small as possible.
Let us first define the cost of a BST. The cost of a BST node is level of that node multiplied by its frequency. Level of root is 1.

Input:
First line consists of test cases T. First line of every test case consists of N, denoting the number of key. Second and Third line consists N spaced elements of keys and frequency respectively.

Output:
Print the most minimum optimal cost.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
2
10 12
34 50
3
10 12 20
34 8 50
Output:
118
142
*/

