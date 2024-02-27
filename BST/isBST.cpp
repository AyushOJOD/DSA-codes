#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

bool isBST(TreeNode *root, int min, int max) // here min and max are the range of the root node i.e, INT_MIN and INT_MAX
{
    if (root == NULL)
    {
        return true;
    }
    return (root->data > min && root->data < max && isBST(root->left, min, root->data) && isBST(root->right, root->data, max));
}

// A tree is BST if its Inorder traversal gives a sorted array

bool isBSTinorder(TreeNode *root)
{
    int prev = INT_MIN;

    if (root == NULL)
    {
        return true;
    }

    if (!isBSTinorder(root->left))
    {
        return false;
    }
    if (root->data < prev)
    {
        return false;
    }
    prev = root->data;
    return isBSTinorder(root->right);
}

int main()
{

    // Creating nodes for the BST
    TreeNode *root = new TreeNode(8);
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(10);
    TreeNode *node3 = new TreeNode(1);
    TreeNode *node4 = new TreeNode(6);
    TreeNode *node5 = new TreeNode(14);
    TreeNode *node6 = new TreeNode(4);
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node8 = new TreeNode(13);

    // Constructing the BST
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node4->left = node6;
    node4->right = node7;
    node2->right = node5;
    node5->left = node8;

    if (isBST(root, INT_MIN, INT_MAX))
    {
        cout << "The given tree is a BST" << endl;
    }
    else
    {
        cout << "The given tree is not a BST" << endl;
    }

    return 0;
}
