#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    pair<TreeNode *, int> helper(TreeNode *root)
    {
        if (!root)
        {
            return {NULL, 0};
        }

        auto [leftLCA, leftDepth] = helper(root->left);
        auto [rightLCA, rightDepth] = helper(root->right);

        if (leftDepth > rightDepth)
        {
            return {leftLCA, leftDepth + 1};
        }
        if (leftDepth < rightDepth)
        {
            return {rightLCA, rightDepth + 1};
        }

        return {root, leftDepth + 1};
    }

public:
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        return helper(root).first;
    }
};

int main()
{

    return 0;
}