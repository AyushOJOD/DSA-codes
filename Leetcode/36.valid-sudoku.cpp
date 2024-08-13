#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {

            char num = board[row][col];

            for (int i = 0; i < 9; i++)
            {
                if (board[row][i] == num)
                {
                    return false;
                }
                if (board[i][col] == num)
                {
                    return false;
                }
                if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

int main()
{

    return 0;
}