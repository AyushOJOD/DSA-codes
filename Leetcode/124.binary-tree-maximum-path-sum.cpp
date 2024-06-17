#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};

int getMaxValue(TreeNode *node, int &maxSum)
{
    if (!node)
    {
        return 0;
    }

    int max_left_value = max(0, getMaxValue(node->left, maxSum));
    int max_right_value = max(0, getMaxValue(node->right, maxSum));

    maxSum = max(maxSum, max_left_value + max_right_value + node->val);

    return max(max_left_value, max_right_value) + node->val;
}

int maxPathSum(TreeNode *root)
{
    int maxSum = INT_MIN;
    getMaxValue(root, maxSum);
    return maxSum;
}

int main()
{

    return 0;
}