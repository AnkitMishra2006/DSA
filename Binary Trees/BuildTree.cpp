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

void preOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    vector<int> pre = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(pre);

    cout << "Pre-order traversal of the constructed tree: ";
    preOrder(root);

    return 0;
}