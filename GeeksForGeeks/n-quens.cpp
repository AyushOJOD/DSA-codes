#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isValid(vector<vector<int>> &board, int col, int row, int n)
    {
        int dupRow = row;
        int dupCol = col;

        // Top
        while (row >= 0)
        {
            if (board[row][col] == 1)
            {
                return false;
            }
            row--;
        }

        row = dupRow, col = dupCol;

        // top left
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 1)
            {
                return false;
            }
            row--;
            col--;
        }

        row = dupRow, col = dupCol;

        // top right
        while (row >= 0 && col < n)
        {
            if (board[row][col] == 1)
            {
                return false;
            }
            row--;
            col++;
        }

        return true;
    }

    void helper(vector<vector<int>> &board, vector<vector<int>> &res, vector<int> &curr, int currRow, int n)
    {
        if (currRow == n)
        {
            res.push_back(curr);
            return;
        }

        for (int i = 1; i <= n; i++)
        {
            if (isValid(board, i - 1, currRow, n))
            {
                board[currRow][i - 1] = 1;
                curr.push_back(i);
                helper(board, res, curr, currRow + 1, n);
                curr.pop_back();
                board[currRow][i - 1] = 0;
            }
        }
    }

public:
    vector<vector<int>> nQueen(int n)
    {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<int>> res;
        vector<int> curr;

        helper(board, res, curr, 0, n);

        return res;
    }
};

int main()
{

    return 0;
}