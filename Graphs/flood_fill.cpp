#include <bits/stdc++.h>
using namespace std;

// Basic Idea: We used DFS to traverse the image and change the color of the pixels

void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int initialColor, int newColor, int delRow[], int delCol[])
{
    ans[row][col] = newColor;
    int n = ans.size();
    int m = ans[0].size();

    for (int i = 0; i < 4; i++)
    {
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];

        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == initialColor && ans[nRow][nCol] != newColor)
        {
            dfs(nRow, nCol, ans, image, initialColor, newColor, delRow, delCol);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    // Code here
    int initialColor = image[sr][sc];
    vector<vector<int>> ans = image;
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    dfs(sr, sc, ans, image, initialColor, newColor, delRow, delCol);

    return ans;
}

int main()
{

    return 0;
}