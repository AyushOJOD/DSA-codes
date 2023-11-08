#include <bits/stdc++.h>
using namespace std;

void printBoundry(int arr[m][n])
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
        for (int i = 0; i < n; i++)
        {
            cout << arr[0][i] << " ";
        }
        for (int i = 2; i < m; i++)
        {
            cout << arr[i][n] << " ";
        }
        for (int i = n - 1; i > 0; i--)
        {
            cout << arr[m][i] << " ";
        }
        for (int i = m - 1; i > 0; i--)
        {
            cout << arr[i][0] << " ";
        }
    }
}

int main()
{

    return 0;
}