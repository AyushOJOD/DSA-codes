int countSubmatrices(vector<vector<int>> &grid, int target)
{
    int res = 0, rows = grid.size(), cols = grid[0].size();

    for (int row = 0; row < rows; row++)
    {
        for (int col = 1; col < cols; col++)
        {
            grid[row][col] += grid[row][col - 1];
        }
    }

    for (int col = 0; col < cols; col++)
    {
        int add = 0;
        for (int row = 0; row < rows; row++)
        {
            add += grid[row][col];
            if (add <= target)
                res++;
        }
    }

    return res;
}