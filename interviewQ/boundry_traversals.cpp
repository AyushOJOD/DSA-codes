#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        val = x;
        left = right = NULL;
    }
};

void leftHalf(Node *node, vector<int> &ans)
{
    if (!node || (!node->left && !node->right))
    {
        return;
    }

    ans.push_back(node->val);

    if (node->left)
    {
        leftHalf(node->left, ans);
    }
    else
    {
        leftHalf(node->right, ans)
    }
}

void getLeafNodes(Node *node, vector<int> &ans)
{
    if (!node)
    {
        return;
    }
    if (!node->left && !node->right)
    {
        ans.push_back(node->val);
        return;
    }

    getLeafNodes(node->left, ans);
    getLeafNodes(node->right, ans);
}

void rightHalf(Node *node, vector<int> &ans)
{
    if (!node || (!node->left && !node->right))
    {
        return;
    }

    if (node->right)
    {
        rightHalf(node->right, ans);
    }
    else
    {
        rightHalf(node->left, ans);
    }

    ans.push_back(node->val);
}

void boundryTraversal(Node *root)
{
    vector<int> ans;
    if (!root)
    {
        return ans;
    }

    // push the left half
    leftHalf(root->left, ans);

    // push the leaf nodes

    // Push the left half leaves
    getLeafNodes(root->left, ans);

    // Push the right half leaves
    getLeafNodes(root->right, ans);

    // Push the right half in reverse order
    rightHalf(root->right, ans);

    return ans;
}

int main()
{

    return 0;
}