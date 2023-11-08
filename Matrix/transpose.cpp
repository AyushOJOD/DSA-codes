#include <bits/stdc++.h>
using namespace std;

int transpose(int arr[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

int main()
{

    return 0;
}