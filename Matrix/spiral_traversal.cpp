#include <bits/stdc++.h>
using namespace std;

int spiralTraversal(int arr[m][n])
{
    if (m == 1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[1][i] << " ";
        }
    }
    else if (n == 1)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[m][i] << " ";
        }
    }

    else
    {
        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        while (top < bottom || left < right)
        {
            for (int i = left; i <= right; i++)
            {
                cout << arr[top][i] << " ";
            }
            top++;
            for (int i = top; i <= bottom; i++)
            {
                cout << arr[i][right] << " ";
            }
            right--;
            for (int i = right; i >= left; i--)
            {
                cout << arr[bottom][i] << " ";
            }
            bottom--;
            for (int i = bottom; i >= top; i--)
            {
                cout << arr[i][left];
            }
            left++;
        }
    }
}

int main()
{

    return 0;
}