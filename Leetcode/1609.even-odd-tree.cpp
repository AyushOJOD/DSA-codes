#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isEvenOddTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }

    queue<TreeNode *> q;
    q.push(root);
    int level = 0;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> levelNodes;

        for (int i = 0; i < size; ++i)
        {
            TreeNode *node = q.front();
            q.pop();

            if (level % 2 == 0)
            {
                if (i > 0 && node->val <= levelNodes.back())
                {
                    return false;
                }
                if (node->val % 2 == 0)
                {
                    return false;
                }
            }
            else
            {
                if (i > 0 && node->val >= levelNodes.back())
                {
                    return false;
                }
                if (node->val % 2 != 0)
                {
                    return false;
                }
            }

            levelNodes.push_back(node->val);

            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }

        ++level;
    }

    return true;
}

int main()
{
    // Example usage:
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(10);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(2);

    if (isEvenOddTree(root))
    {
        cout << "The tree satisfies the conditions." << endl;
    }
    else
    {
        cout << "The tree does not satisfy the conditions." << endl;
    }

    return 0;
}
