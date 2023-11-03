#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};

    sort(v.begin(), v.end(), [](int n1, int n2)
         {
        if (__builtin_popcount(n1) < __builtin_popcount(n2)) {
            return true;
        }
        if (__builtin_popcount(n1) == __builtin_popcount(n2)) {
            return n1 < n2;
        }
        return false; });

    for (int num : v)
    {
        cout << num << " ";
    }

    return 0;
}
