#include <bits/stdc++.h>
using namespace std;

bool isVowel(char &ch)
{
    const unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};

    return vowel.find(ch) != vowel.end();
}

int helper(string &s, int a, int b, int sum, int n)
{
    int left = 0, right = 0, currSum = 0, count = 0;

    while (right < n)
    {
        currSum += (isVowel(s[right])) ? a : b;

        while (currSum > sum)
        {
            currSum -= (isVowel(s[left])) ? a : b;
            left++;
        }

        count += (right - left + 1);
        right++;
    }

    return count;
}

int solve(string &s, int a, int b)
{
    int k = s.length();

    return helper(s, a, b, k, k) - helper(s, a, b, k - 1, k);
}

int main()
{

    string word = "abbacc";
    int a = -1, b = 2;

    cout << solve(word, a, b);

    return 0;
}