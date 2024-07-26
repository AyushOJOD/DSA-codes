#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    string RLE(string s)
    {

        int currFreq = 1;
        vector<pair<int, int>> encode;
        char currChar = s[0];
        int idx = 0;

        while (idx < s.length())
        {
            while (s[idx] == currChar)
            {
                currFreq++;
                idx++;
            }

            encode.push_back({currFreq, currChar});

            s[idx] = currChar;
            currFreq = 1;
        }

        string res = "";

        for (auto it : encode)
        {
            char freq = char(it.first);
            char number = char(it.second);

            res += freq;
            res += number;
        }

        return res;
    }

public:
    string countAndSay(int n)
    {
        if (n == "1")
        {
            return "1";
        }

        return RLE(to_string(n));
    }
};

int main()
{

    return 0;
}