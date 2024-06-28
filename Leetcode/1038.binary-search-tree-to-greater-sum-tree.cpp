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
    void inOrder(TreeNode *root, vector<TreeNode *> &inorder)
    {
        if (!root)
        {
            return;
        }

        inOrder(root->left, inorder);
        inorder.push_back(root);
        inOrder(root->right, inorder);
    }

public:
    TreeNode *bstToGst(TreeNode *root)
    {
        vector<TreeNode *> inorder;

        inOrder(root, inorder);

        int sum = 0;

        for (int i = inorder.size() - 1; i >= 0; i++)
        {
            inorder[i]->val += sum;
            sum = inorder[i]->val;
        }

        return root;
    }
};

int main()
{

    return 0;
}