#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &image, int sr, int sc, int color, int source, int row, int col)
{
    if (sr < 0 || sr > row || sc < 0 || sc > col)
    {
        return;
    }
    else if (image[sr][sc] != source)
    {
        return;
    }

    image[sr][sc] = color;

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        int nRow = sr + delRow[i];
        int nCol = sc + delCol[i];

        dfs(image, nRow, nCol, color, source, row, col);
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc)
{
    int n = image.size();
    int m = image[0].size();

    if (color == image[sr][sc])
    {
        return image;
    }

    int source = image[sr][sc];

    dfs(image, sr, sc, color, source, n, m);

    return image;
}

int main()
{

    return 0;
}