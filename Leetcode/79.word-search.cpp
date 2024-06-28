#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool helper(string word, vector<vector<char>> &board, int row, int col, int idx, int m, int n)
    {
        if (idx == word.length())
        {
            return true;
        }

        if (row < 0 || row >= n || col < 0 || col >= m || board[row][col] == '#' || board[row][col] != word[idx])
        {
            return false;
        }

        char ch = board[row][col];
        board[row][col] = '#';

        bool up = helper(word, board, row - 1, col, idx + 1, m, n);

        bool left = helper(word, board, row, col - 1, idx + 1, m, n);

        bool down = helper(word, board, row + 1, col, idx + 1, m, n);

        bool right = helper(word, board, row, col + 1, idx + 1, m, n);

        board[row][col] = ch;

        return up || left || down || right;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();

        int idx = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[idx] && helper(word, board, i, j, idx, m, n))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{

    return 0;
}