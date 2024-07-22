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
    void getParent(TreeNode *root, vector<TreeNode *> &parent, int value, TreeNode *&start)
    {
        queue<TreeNode *> q;
        q.push(root);
        parent[root->val] = nullptr;

        if (root->val == value)
        {
            start = root;
        }

        while (!q.empty())
        {
            TreeNode *it = q.front();
            q.pop();

            if (it->left)
            {
                parent[it->left->val] = it;
                q.push(it->left);

                if (it->left->val == value)
                {
                    start = it->left;
                }
            }
            if (it->right)
            {
                parent[it->right->val] = it;
                q.push(it->right);

                if (it->right->val == value)
                {
                    start = it->right;
                }
            }
        }
    }

public:
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        if (!root)
            return "";

        vector<TreeNode *> parent(100001, nullptr);
        vector<bool> vis(100001, false);

        TreeNode *start = nullptr;
        getParent(root, parent, startValue, start);

        if (!start)
            return "";

        queue<pair<string, TreeNode *>> q; // {path, node}
        q.push({"", start});
        vis[start->val] = true;

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            string path = it.first;
            TreeNode *currNode = it.second;

            if (currNode->val == destValue)
            {
                return path;
            }

            if (currNode->left && !vis[currNode->left->val])
            {
                vis[currNode->left->val] = true;
                q.push({path + 'L', currNode->left});
            }

            if (currNode->right && !vis[currNode->right->val])
            {
                vis[currNode->right->val] = true;
                q.push({path + 'R', currNode->right});
            }
            if (parent[currNode->val] != nullptr && !vis[parent[currNode->val]->val])
            {
                vis[parent[currNode->val]->val] = true;
                q.push({path + 'U', parent[currNode->val]});
            }
        }
        return "";
    }
};

int main()
{

    return 0;
}