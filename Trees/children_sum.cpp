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

bool isSumProperty(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }

    int left = root->left != NULL ? root->left->val : 0;
    int right = root->right != NULL ? root->right->val : 0;

    if (left + right != root->val)
    {
        return false;
    }
    return isSumProperty(root->left) && isSumProperty(root->right);
}

int main()
{

    return 0;
}