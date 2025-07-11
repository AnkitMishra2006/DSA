#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
static int idx = -1;
Node *buildTree(vector<int> pre)
{
    idx++;
    if (idx >= pre.size() || pre[idx] == -1)
    {
        return nullptr;
    }
    Node *newNode = new Node(pre[idx]);
    newNode->left = buildTree(pre);
    newNode->right = buildTree(pre);
    return newNode;
}

int main()
{
    vector<int> pre = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(pre);
    cout << root->data << endl;        // Output the root node's data
    cout << root->left->data << endl;  // Output the left child node's data
    cout << root->right->data << endl; // Output the right child node's data

    return 0;
}