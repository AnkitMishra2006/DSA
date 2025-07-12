#include <iostream>
#include <vector>
#include <algorithm>
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

void postOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void levelOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    levelOrder(root->left);
    levelOrder(root->right);
}

int main()
{
    vector<int> pre = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(pre);

    cout << "Pre-order traversal of the constructed tree: ";
    preOrder(root);
    cout << endl;
    cout << "Post-order traversal of the constructed tree: ";
    postOrder(root);
    cout << endl;
    cout << "In-order traversal of the constructed tree: ";
    inOrder(root);
    cout << endl;
    cout << "Level-order traversal of the constructed tree: ";
    levelOrder(root);
    cout << endl;

    return 0;
}