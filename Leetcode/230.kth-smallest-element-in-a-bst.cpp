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
public:
    void getInorder(TreeNode *root, vector<int> &inOrder)
    {
        if (!root)
        {
            return root;
        }

        getInorder(root->left, inOrder);
        inOrder.push_back(root->val);
        getInorder(root->right, inOrder);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> inOrder;

        getInorder(root, inOrder);

        return inOrder[k - 1];
    }
};

int main()
{

    return 0;
}