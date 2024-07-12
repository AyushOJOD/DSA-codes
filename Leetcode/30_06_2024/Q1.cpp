#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxHeightOfTriangle(int red, int blue)
    {
        int cnt1 = 0, cnt2 = 0;

        // placing red on top

        int i = 0, j = 0;

        while (true)
        {
            if (i % 2 == 0)
            {
                if (red >= (i + 1))
                {
                    red -= (i + 1);
                    cnt1++;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (blue >= (i + 1))
                {
                    blue -= (i + 1);
                    cnt1++;
                }
                else
                {
                    break;
                }
            }
        }

        while (true)
        {
            if (i % 2 == 0)
            {
                if (blue >= (i + 1))
                {
                    blue -= (i + 1);
                    cnt2++;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (red >= (i + 1))
                {
                    red -= (i + 1);
                    cnt2++;
                }
                else
                {
                    break;
                }
            }
        }

        return max(cnt1, cnt2);
    }
};

int main()
{

    return 0;
}