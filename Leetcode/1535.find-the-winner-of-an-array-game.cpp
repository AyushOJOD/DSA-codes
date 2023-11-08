#include <bits/stdc++.h>
using namespace std;

int getWinner(vector<int> &arr, int k)
{
    int left = 0;
    int right = 1;

    int wins = 0;

    while (wins < k)
    {
        if (arr[left] > arr[right])
        {
            wins++;
            right++;
        }
        else
        {
            left = right;
            right++;
            wins = 1;
        }
    }

    return arr[left];
}

int main()
{
    vector<int> arr = {2, 1, 3, 5, 4, 6, 7};
    int k = 2;
    cout << "The winner is: " << getWinner(arr, k);

    return 0;
}