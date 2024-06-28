#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{

public:
    void recoverTree(TreeNode *root)
    {
        TreeNode *first = NULL, *second = NULL;

        TreeNode *curr = root;

        if (!curr)
        {
            return;
        }

        recoverTree(root->left);
        // Apply the logic
        if (root->left && root->left->val > root->val)
        {
            if (!first)
            {
                first = root;
            }
            else
            {
                second = root;
            }
        }
        else if (root->right && root->right->val < root->val)
        {
            if (!first)
            {
                first = root;
            }
            else
            {
                second = root;
            }
        }

        recoverTree(root->right);

        if (first && second)
        {
            swap(first->val, second->val);
        }
    }
};

int main()
{

    return 0;
}