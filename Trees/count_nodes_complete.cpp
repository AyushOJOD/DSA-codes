#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

//  A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

int countNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{

    return 0;
}