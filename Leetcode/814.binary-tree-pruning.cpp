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
public:
    TreeNode *pruneTree(TreeNode *root)
    {
        if (!root)
        {
            return root;
        }

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if (!root->val && !root->left && !root->right)
        {
            return nullptr;
        }

        return root;
    }
};

int main()
{

    return 0;
}