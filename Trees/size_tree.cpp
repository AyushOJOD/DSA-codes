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

int size(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + size(root->left) + size(root->right);
}

int main()
{

    return 0;
}