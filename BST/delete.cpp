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

TreeNode *getSuccessor(TreeNode *curr)
{
    curr = curr->right;

    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }

    return curr;
}

TreeNode *delete(TreeNode *root, int x)
{
    if (root == NULL)
        return root;

    if (root->val < x)
    {
        root->right = delete (root->right, x);
    }
    else if (root->val > x)
    {
        root->left = delete (root->left, x);
    }
    else
    {
        if (root->left == NULL)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            TreeNode *succ = getSuccessor(root);
            root->val = succ->val;
            root->right = delete (root->right, x);
        }
    }
}

int main()
{

    return 0;
}