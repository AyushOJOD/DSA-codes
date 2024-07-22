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
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_map<int, pair<int, int>> treeMap; // {parent , {leftChild, rightChild}}
        unordered_set<int> children;

        for (auto it : descriptions)
        {
            int parent = it[0];
            int child = it[1];
            bool isLeft = it[2];

            if (isLeft)
            {
                treeMap[parent].first = child;
            }
            else
            {
                treeMap[parent].second = child;
            }

            children.insert(child);
        }

        int rootVal = 0;

        for (auto it : descriptions)
        {
            int parent = it[0];

            if (children.find(parent) == children.end())
            {
                rootVal = parent;
                break;
            }
        }

        TreeNode *root = (root != 0) ? new TreeNode(rootVal) : new TreeNode(-1);

        for (auto it : treeMap)
        {
            int parent = it.first;
            int leftChild = it.second.first;
            int rightChild = it.second.second;

            TreeNode *leftNode = new TreeNode(leftChild);
            TreeNode *rightNode = new TreeNode(rightChild);

            if (parent == rootVal)
            {
                root->left = leftNode;
                root->right = rightNode;
            }
            else
            {
                TreeNode *newRoot = new TreeNode(parent);

                newRoot->left = leftNode;
                newRoot->right = rightNode;
            }
        }

        return root;
    }
};

int main()
{

    return 0;
}