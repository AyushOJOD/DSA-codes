#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // There should be only 3 . and b/w every dot there must be 3 numbers stoi of which should be [0, 255]
public:
    int isValid(string str)
    {
        int n = str.length();

        int dots = 0;

        for (int i = 0; i < n; i++)
        {
            string num = "";
            while (i < n && str[i] != '.')
            {
                num += str[i];
                i++;
            }
            if (str[i] == '.')
                dots++;
            int value = stoi(num);
            if (value > 255)
                return false;
        }
        return (dots == 3);
    }
};

int main()
{

    return 0;
}