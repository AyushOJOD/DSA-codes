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

int getNode(int el, vector<int> &inorder)
{
    for (int i = 0; i < inorder.size(); i++)
    {
        if (inorder[i] == el)
        {
            return i;
        }
    }
    return -1;
}

TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int &index, int inOrderStart, int inOrderEnd)
{
    int n = preorder.size();

    if (index >= n || inOrderEnd < inOrderStart)
    {
        return NULL;
    }

    int element = preorder[index++];
    TreeNode *node = new TreeNode(element);
    int position = getNode(element, inorder);

    // Recursive calls

    node->left = helper(preorder, inorder, index, inOrderStart, position - 1);
    node->right = helper(preorder, inorder, index, position + 1, inOrderEnd);

    return node;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    return helper(preorder, inorder, 0, 0, inorder.size() - 1);
}

int main()
{

    return 0;
}