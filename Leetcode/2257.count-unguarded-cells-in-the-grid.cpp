#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void markCells(vector<vector<int>> &mat, int row, int col)
    {
        for (int r = row + 1; r < R; r++)
        {
            if (mat[r][col] == 1 || mat[r][col] == 2)
            {
                break;
            }
            mat[r][col] = 3;
        }

        for (int r = row - 1; r >= 0; r--)
        {
            if (mat[r][col] == 1 || mat[r][col] == 2)
            {
                break;
            }
            mat[r][col] = 3;
        }

        for (int c = col + 1; c < C; c++)
        {
            if (mat[row][c] == 1 || mat[row][c] == 2)
            {
                break;
            }
            mat[row][c] = 3;
        }

        for (int c = col - 1; c >= 0; c--)
        {
            if (mat[row][c] == 1 || mat[row][c] == 2)
            {
                break;
            }
            mat[row][c] = 3;
        }
    }

public:
    int R, C;
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        R = m, C = n;
        vector<vector<int>> mat(m, vector<int>(n, 0)); // 0=free 1=gaurd 2=wall 3=gaurded

        for (auto gaurd : guards)
        {
            mat[gaurd[0]][gaurd[1]] = 1;
        }

        for (auto wall : walls)
        {
            mat[wall[0]][wall[1]] = 2;
        }

        for (auto gaurd : guards)
        {
            markCells(mat, gaurd[0], gaurd[1]);
        }

        int res = 0;

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (mat[i][j] == 0)
                {
                    res++;
                }
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}