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
    int camera = 0;

    int helper(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int leftTree = helper(root->left);
        int rightTree = helper(root->right);

        if (leftTree == -1 || rightTree == -1)
        {
            camera++;
            return 1;
        }
        if (leftTree == 1 || rightTree == 1)
        {
            return 0;
        }
        return -1;
    }

    int minCameraCover(TreeNode *root)
    {
        if (helper(root) == -1)
        {
            return camera + 1;
        }

        return camera;
    }
};

int main()
{

    return 0;
}