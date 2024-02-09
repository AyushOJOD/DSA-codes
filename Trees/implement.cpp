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

void inOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void preOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

int main()
{

    // If we make TreeNode *root = NULL hence tree is empty

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    return 0;
}