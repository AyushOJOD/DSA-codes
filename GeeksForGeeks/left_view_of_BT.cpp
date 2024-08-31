#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void helper(Node *root, int level, vector<int> &res)
{
    if (!root)
    {
        return;
    }

    if (res.size() == level)
    {
        res.push_back(root->data);
    }

    helper(root->left, level + 1, res);
    helper(root->right, level + 1, res);
}

vector<int> leftView(Node *root)
{
    vector<int> res;

    helper(root, 0, res);

    return res;
}

int main()
{

    return 0;
}