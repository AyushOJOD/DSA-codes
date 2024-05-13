#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<string>> &board, int row, int col, int n)
{
    // check upper left diagonal

    int dupRow = row;
    int dupCol = col;

    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        row--;
        col--;
    }

    col = dupCol;
    row = dupRow;

    // checking the same row
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        col--;
    }

    // checking the lower diagonal

    row = dupRow;
    col = dupCol;

    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        row++;
        col--;
    }

    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &res, int n)
{
    if (col == n)
    {
        res.push_back(board);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isValid(board, i, col, n))
        {
            board[i][col] == 'Q';
            solve(col + 1, board, res, n);
            board[i][col] == '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> res;
    vector<string> board(n);
    string s(n, '.');

    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }

    solve(0, board, res, n);

    return res;
}

int main()
{

    return 0;
}