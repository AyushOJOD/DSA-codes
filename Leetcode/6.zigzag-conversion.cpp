#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows <= s.length())
        {
            return s;
        }

        int cols = s.length() / numRows + (s.length() % numRows != 0);

        vector<vector<char>> encode(numRows, vector<char>(col, '#'));
    }
};

int main()
{

    return 0;
}