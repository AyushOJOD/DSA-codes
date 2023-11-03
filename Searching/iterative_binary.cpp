// find the middle element and compare only left or right accordingly

#include <bits/stdc++.h>
using namespace std;

int itrativeBinary(int arr[], int n, int k)
{
    int low = 0;
    int high = n - 1;
    while (high >= low)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] > k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << itrativeBinary(a, n, 5);

    return 0;
}