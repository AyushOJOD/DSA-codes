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
    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int &idx, int inorderStart, int inorderEnd, unordered_map<int, int> &inOrderFind)
    {
        if (idx < 0 || inorderStart > inorderEnd)
        {
            return nullptr;
        }

        int element = postorder[idx--];
        TreeNode *node = new TreeNode(element);
        int position = inOrderFind[element];

        // Recursion: right subtree first, then left subtree
        node->right = helper(inorder, postorder, idx, position + 1, inorderEnd, inOrderFind);
        node->left = helper(inorder, postorder, idx, inorderStart, position - 1, inOrderFind);

        return node;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> inOrderFind;
        for (int i = 0; i < inorder.size(); i++)
        {
            inOrderFind[inorder[i]] = i;
        }

        int idx = postorder.size() - 1;
        return helper(inorder, postorder, idx, 0, inorder.size() - 1, inOrderFind);
    }
};
{
}

int main()
{

    return 0;
}
