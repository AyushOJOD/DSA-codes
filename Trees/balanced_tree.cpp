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

int isBalanced(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int left = isBalanced(root->left);
    if (left == -1)
        return -1; // if left subtree is not balanced then return -1

    int right = isBalanced(root->right);
    if (right == -1)
        return -1; // if right subtree is not balanced then return -1

    if (abs(left - right) > 1)
        return -1; // if difference between left and right subtree is greater than 1 then return -1

    return max(left, right) + 1; // return the height of the tree
}

int main()
{

    return 0;
}