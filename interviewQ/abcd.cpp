#include <bits/stdc++.h>
using namespace std;

int getRopesCount(const vector<int> &a, int length)
{
    int count = 0;
    for (int rope : a)
    {
        count += rope / length;
    }
    return count;
}

int solution(vector<int> &a, int k)
{
    int left = 1;
    int right = *max_element(a.begin(), a.end());
    int result = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (getRopesCount(a, mid) >= k)
        {
            result = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return result;
}

int main()
{

    vector<int> v = {1, 2, 3, 4, 9};
    int k = 6;

    cout << solution(v, k);

    return 0;
}