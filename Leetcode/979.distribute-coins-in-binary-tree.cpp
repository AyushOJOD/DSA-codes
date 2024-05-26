#include <bits/stdc++.h>
using namespace std;

int DFS(TreeNode *curr, int &moves)
{
    if (!curr)
        return 0;

    int left = DFS(curr->left, moves);
    int right = DFS(curr->right, moves);

    moves += abs(left) + abs(right);

    return curr->val + left + right - 1;
}

int distributeCoins(TreeNode *root)
{
    int moves = 0;

    DFS(root, moves);

    return moves;
}

int main()
{

    return 0;
}