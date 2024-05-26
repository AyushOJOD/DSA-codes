#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int N, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    int count = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            count += mid - left + 1;
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i < high; i++)
    {
        arr[i] = temp[i - low];
    }

    return count;
}

int mergeSort(int arr[], int N, int low, int high)
{
    int count = 0;

    if (low >= right)
    {
        return count;
    }

    int mid = (low + high) / 2;
    count += mergeSort(arr, N, low, mid);
    count += mergeSort(arr, N, mid + 1, high);

    count += merge(arr, N, low, mid, high);
}

int int inversionCount(int arr[], int N)
{
    // Your Code Here
    return mergeSort(arr, N, 0, N - 1);
}

int main()
{

    return 0;
}