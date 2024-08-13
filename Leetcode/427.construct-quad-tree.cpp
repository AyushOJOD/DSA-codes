#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
private:
    bool isAllSame(vector<vector<int>> &grid, int row, int col, int n)
    {
        int value = grid[row][col];

        for (int i = row; i < (row + n); i++)
        {
            for (int j = col; j < (col + n); j++)
            {
                if (grid[i][j] != value)
                {
                    return false;
                }
            }
        }

        return true;
    }

    Node *solve(vector<vector<int>> &grid, int row, int col, int n)
    {
        if (isAllSame(grid, row, col, n))
        {
            return new Node(grid[row][col], true);
        }

        Node *root = new Node(1, false);

        root->topLeft = solve(grid, row, col, n / 2);
        root->topRight = solve(grid, row, col + n / 2, n / 2);
        root->bottomLeft = solve(grid, row + n / 2, col, n / 2);
        root->bottomRight = solve(grid, row + n / 2, col + n / 2, n / 2);

        return root;
    }

public:
    Node *construct(vector<vector<int>> &grid)
    {
        int n = grid.size();

        return solve(grid, 0, 0, n);
    }
};

int main()
{

    return 0;
}