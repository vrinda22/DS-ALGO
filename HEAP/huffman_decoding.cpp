/*The task is to implement Huffman Encoding and Decoding.

Input:
First line consists of T test cases. Only line of every test case consists of String S.

Output:
Single line output, return the Decoded String.

Constraints:
1<=T<=100
2<=S<=1000

Example:
Input:
2
abc
geeksforgeeks
Output:
abc
geeksforgeeks
*/
#include <bits/stdc++.h>
#define MAX_TREE_HT 256
using namespace std;
map<char, string> codes;
map<char, int> freq;
struct MinHeapNode
{
    char data;
    int freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};
struct compare
{
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};
void printCodes(struct MinHeapNode* root, string str)
{
    if (!root)
        return;
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}
void storeCodes(struct MinHeapNode* root, string str)
{
    if (root==NULL)
        return;
    if (root->data != '$')
        codes[root->data]=str;
    storeCodes(root->left, str + "0");
    storeCodes(root->right, str + "1");
}
priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
void HuffmanCodes(int size)
{
    struct MinHeapNode *left, *right, *top;
    for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++)
        minHeap.push(new MinHeapNode(v->first, v->second));
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    storeCodes(minHeap.top(), "");
}
void calcFreq(string str, int n)
{
    for (int i=0; i<str.size(); i++)
        freq[str[i]]++;
}
string decode_file(struct MinHeapNode* root, string s);
int main()
{
	int t;
	cin>>t;
	while(t--){
	codes.clear();
	freq.clear();
	minHeap=priority_queue <MinHeapNode*, vector<MinHeapNode*>, compare>();
    string str;
	cin>>str;
    string encodedString, decodedString;
    calcFreq(str, str.length());
    HuffmanCodes(str.length());
    /*cout << "Character With there Frequencies:\n";
    for (auto v=codes.begin(); v!=codes.end(); v++)
        cout << v->first <<' ' << v->second << endl;*/
    for (auto i: str)
        encodedString+=codes[i];
    //cout <</* "\nEncoded Huffman data:\n" << */encodedString << endl;
    decodedString = decode_file(minHeap.top(), encodedString);
    cout <</* "\nDecoded Huffman Data:\n" << */decodedString << endl;
	}
    return 0;
}// } Driver Code Ends
string decode_file(struct MinHeapNode* root, string s)
{
    string ans;
    struct MinHeapNode* current=root;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0')
            current=current->left;
        else
            current=current->right;
        if(current->left==NULL && current->right==NULL){
            ans+=current->data;
            current=root;
        }
    }
    return ans+'\0';
}
