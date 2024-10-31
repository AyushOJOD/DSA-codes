#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int generateKey(int num1, int num2, int num3)
    {
        string one = to_string(num1);
        string two = to_string(num2);
        string three = to_string(num3);

        while (one.length() < 4)
            one = '0' + one;
        while (two.length() < 4)
        {
            two = '0' + two;
        }
        while (three.length() < 4)
        {
            three = '0' + three;
        }

        string key = "";

        for (int i = 0; i < 4; i++)
        {
            char minVal = min({one[i], two[i], three[i]});
            key += minVal;
        }

        return stoi(key);
    }
};

int main()
{

    return 0;
}