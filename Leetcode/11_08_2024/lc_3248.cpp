#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int finalPositionOfSnake(int n, vector<string> &commands)
    {
        int curr = 0;

        for (string s : commands)
        {
            if (s == "UP")
            {
                curr -= n;
            }
            else if (s == "RIGHT")
            {
                curr += 1;
            }
            else if (s == "LEFT")
            {
                curr -= 1;
            }
            else if (s == "DOWN")
            {
                curr += n;
            }
        }

        return curr;
    }
};

int main()
{

    return 0;
}