#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    void getInorder(TreeNode *root, vector<int> &inorder)
    {
        if (!root)
        {
            return;
        }

        getInorder(root->left, inorder);
        inorder.push_back(root->val);
        getInorder(root->right, inorder);
    }

private:
    TreeNode *buildTree(vector<int> &inorder, int low, int high)
    {
        if (low > high)
        {
            return NULL;
        }

        int mid = left + (right - left) / 2;
        TreeNode *node = new TreeNode(inorder[mid]);

        node->left = buildTree(inorder, low, mid - 1);
        node->right = buildTree(inorder, mid + 1, high);

        return node;
    }

public:
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> inorder;
        getInorder(root, inorder);

        return buildTree(inorder, 0, inorder.size() - 1);
    }
};

int main()
{

    return 0;
}