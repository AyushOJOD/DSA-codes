#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int count = 0;
        int characters[3] = {-1, -1, -1};

        for (int i = 0; i < s.length(); i++)
        {
            characters[s[i] - 'a'] = i;

            count += 1 + min(characters[0], min(characters[1], characters[2]));
        }

        return count;
    };
};

int main()
{

    return 0;
}