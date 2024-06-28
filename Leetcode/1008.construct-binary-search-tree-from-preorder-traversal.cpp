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
    void buildTree(vector<int> &preorder, int &idx, int bound)
    {
        if (idx >= preorder.size() || preorder[idx] > bound)
        {
            return NULL;
        }
        TreeNode *node = new TreeNode(preorder[idx++]);
        node->left = buildTree(preorder, idx, node->val);
        node->right = buildTree(preorder, idx, bound);
        return node;
    }

public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        return buildTree(preorder, i, INT_MAX);
    }
};

int main()
{

    return 0;
}