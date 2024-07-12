#include <bits/stdc++.h>
using namespace std;

// left = 1
// right = 2

// "AABABBA"
// k = 1

// A -> 1
// B -> 1

// maxLength = 2

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int left = 0, right = 0, maxLength = 0;
        unordered_map<char, int> freq; // {char -> freq}

        while (right < s.length())
        {
            freq[s[right]]++;

            if (freq.size() > k)
            {
                freq[s[left]]--;
                if (freq[s[left]] == 0)
                {
                    freq.erase(s[left]);
                }
                left++;
            }

            int len = right - left + 1;
            maxLength = max(len, maxLength);

            right++;
        }

        return maxLength;
    }
};

int main()
{

    return 0;
}