#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumCost(int m, int n, vector<int> &horizontalCut, vector<int> &verticalCut)
    {
        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());

        int row = 0, col = 0;
        int Rowpiece = 1, ColPiece = 1;
        int res = 0;
        while (row < m - 1 && col < n - 1)
        {
            if (horizontalCut[row] > verticalCut[col])
            {
                res += horizontalCut[row] * ColPiece;
                Rowpiece++;
                row++;
            }
            else
            {
                res += verticalCut[col] * Rowpiece;
                ColPiece++;
                col++;
            }
        }

        while (col < verticalCut.size())
        {
            res += verticalCut[col] * Rowpiece;
            col++;
        }

        while (row < horizontalCut.size())
        {
            res += horizontalCut[row] * ColPiece;
            row++;
        }

        return res;
    }
};
