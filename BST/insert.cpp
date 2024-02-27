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

TreeNode *insert(TreeNode *root, int key)
{
    if (root == NULL)
    {
        return new TreeNode(key);
    }
    if (root->val == key)
        return root; // if the key is already present in the tree, return the root (no duplicates allowed

    else if (root->val < key)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        root->left = insert(root->left, key);
    }

    return root;
}

int main()
{

    return 0;
}