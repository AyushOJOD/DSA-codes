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

int height(TreeNode *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int diameter(TreeNode *root)
{

    if (root == NULL)
        return 0;

    int d1 = diameter(root->left);
    int d2 = diameter(root->right);
    int d3 = 1 + height(root->left) + height(root->right);

    return max(d1, max(d2, d3));
}

int main()
{

    return 0;
}