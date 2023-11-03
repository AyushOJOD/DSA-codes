#include <bits/stdc++.h>
using namespace std;

vector<int> sortByBits(vector<int> &arr)
{

    sort(arr.begin(), arr.end(), [](int n1, int n2)
         {
        if (__builtin_popcount(n1) < __builtin_popcount(n2)) {
            return true;
        }
        if (__builtin_popcount(n1) == __builtin_popcount(n2)) {
            return n1 < n2;
        }
        return false; });

    for (int num : sorted)
    {
        cout << num << " ";
    }
}

int main()
{
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> sorted = sortByBits(v);

    for (int num : sorted)
    {
        cout << num << " ";
    }

    return 0;
}
