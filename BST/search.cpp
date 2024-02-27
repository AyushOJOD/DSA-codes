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

TreeNode *search(TreeNode *root, int key)
{
    if (root == NULL)
    {
        return -1;
    }
    else if (root->val == key)
    {
        return root;
    }

    if (root->val < key)
    {
        return search(root->right, key);
    }
    else
    {
        return search(root->left, key);
    }
}

int main()
{

    return 0;
}