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
    typedef long long ll;

    vector<ll> getBfsSum(TreeNode *root)
    {
        vector<ll> res;

        if (!root)
        {
            return res;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            ll levelSum = 0;

            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                levelSum += curr->val;

                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
            res.push_back(levelSum);
        }

        return res;
    }

    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        vector<ll> BfsSum = getBfsSum(root);

        if (BfsSum.size() < k)
        {
            return -1;
        }

        sort(BfsSum.begin(), BfsSum.end(), greater<ll>());

        return BfsSum[k - 1];
    }
};

int main()
{

    return 0;
}