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

int ceiling(TreeNode *root, int x)
{
    int res = -1;

    while (root)
    {
        if (root->val == x)
        {
            return root->val;
        }
        else if (root->val < x)
        {
            root = root->right;
        }
        else
        {
            res = root;
            root = root->left;
        }
    }
}

int main()
{

    return 0;
}