#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class NodeValue
{
public:
    int maxNode, minNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->maxNode = maxNode;
        this->maxSize = maxSize;
        this->minNode = minNode;
    }
}

class Solution
{
private:
    NodeValue helper(Node *root)
    {
        if (!root)
        {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        if (left.maxNode < root->data && right.minNode > root->data)
        {
            return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), 1 + left.maxSize + right.maxSize);
        }

        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    int largestBst(Node *root)
    {
        // Your code here
        return helper(root).maxSize;
    }
};

int main()
{

    return 0;
}