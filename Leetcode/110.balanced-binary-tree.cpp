#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getHeight(TreeNode *node)
{
    if (!node)
    {
        return 0;
    }

    int maxLeft = getHeight(node->left);
    int maxRight = getHeight(node->right);

    return max(maxLeft, maxRight) + 1;
}

bool isBalanced(TreeNode *root)
{
    if (!root)
    {
        return true;
    }

    int leftVal = getHeight(root->left);
    int rightVal = getHeight(root->right);
}

int main()
{

    return 0;
}