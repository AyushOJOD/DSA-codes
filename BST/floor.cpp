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

// Returns the maximum value in the BST which is less than or equal to x.

int floor(TreeNode *root, int x)
{

    int res = -1;

    while (root != NULL)
    {
        if (root->val == x)
        {
            return root->val;
        }
        else if (root->val > x)
        {
            root = root->left;
        }
        else
        {
            res = root->val;
            root = root->right;
        }
    }
}

int main()
{

    return 0;
}