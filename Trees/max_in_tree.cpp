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

int max_in_tree(TreeNode *root)
{
    if (root == NULL)
        return INT_MIN;

    return max(root->val, max(max_in_tree(root->left), max_in_tree(root->right)));
}

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->left->left->left = new TreeNode(10);
    root->left->left->left->right = new TreeNode(11);
    root->left->left->left->left->left = new TreeNode(12);

    cout << max_in_tree(root);

    return 0;
}