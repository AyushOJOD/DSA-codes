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
    void helper(TreeNode *root, int sum, vector<int> curr, vector<vector<int>> &ans)
    {
        if (!root)
        {
            return;
        }

        curr.push_back(root->val);

        if (!root->left && !root->right && sum - root->val == 0)
        {
            ans.push_back(curr);
        }

        helper(root->left, sum - root->val, curr, ans);
        helper(root->right, sum - root->val, curr, ans);
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> curr;

        if (!root)
        {
            return ans;
        }

        helper(root, targetSum, curr, ans);

        return ans;
    }
};

int main()
{

    return 0;
}