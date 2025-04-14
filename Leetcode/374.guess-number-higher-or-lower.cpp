#include <bits/stdc++.h>
using namespace std;

int guess(int num)
{
}

class Solution
{
public:
    int guessNumber(int n)
    {
        int left = 1, right = n;

        while (left <= right)
        {
            int mid = (left + (right - left) / 2);

            if (guess(mid) == 0)
            {
                return mid;
            }
            else if (guess(mid) == 1)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return -1;
    }
};

int main()
{

    return 0;
}