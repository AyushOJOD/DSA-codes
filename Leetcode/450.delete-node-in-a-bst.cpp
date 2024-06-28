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
    TreeNode *helper(TreeNode *node)
    {
        if (!node->left)
        {
            return node->right;
        }
        else if (!node->right)
        {
            return node->left;
        }

        TreeNode *rightChild = node->right;
        TreeNode *rightMostChild = getRightMostChild(node->left);

        rightMostChild->right = rightChild;

        return node;
    }

    TreeNode *getRightMostChild(TreeNode *node)
    {
        if (!node->right)
        {
            return node;
        }

        return getRightMostChild(node->right);
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
        {
            return NULL;
        }

        if (root->val == key)
        {
            return helper(root);
        }

        TreeNode *curr = root;

        while (curr)
        {
            if (curr->val > key)
            {
                if (curr->left && curr->left->val == key)
                {
                    curr->left = helper(curr->left);
                    break;
                }
                else
                {
                    curr = curr->left;
                }
            }
            else
            {
                if (curr->right && curr->right->val == key)
                {
                    curr->right = helper(curr->right);
                    break;
                }
                else
                {
                    curr = curr->right;
                }
            }
        }
        return root;
    }
};

int main()
{

    return 0;
}