#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isValid(int row, int col, vector<string> &board, int n)
    {
        int r = row;
        int c = col;

        // top left
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            row--;
            col--;
        }

        row = r;
        col = c;

        // left
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            col--;
        }

        row = r;
        col = c;

        // bottom left
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            col--;
            row++;
        }

        return true;
    }

    void solve(vector<string> &board, int currCol, int n, int &cnt)
    {
        if (currCol == n)
        {
            cnt++;
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (isValid(i, currCol, board, n))
            {
                board[i][currCol] = 'Q';
                solve(board, currCol + 1, n, cnt);
                board[i][currCol] = '.';
            }
        }
    }

public:
    int totalNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        int cnt = 0;

        solve(board, 0, n, cnt);

        return cnt;
    }
};

int main()
{

    return 0;
}