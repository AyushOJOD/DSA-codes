#include <bits/stdc++.h>
using namespace std;

class Solution
{
#define MOD 1000000007

private:
    int helper(string &word, int k, int curr, int prev)
    {
        if (curr >= k)
        {
            return 1;
        }

        int notTake = 0, take = 0;

        if (prev != -1 && word[prev] == word[curr])
        {
            notTake = helper(word, k, curr + 1, prev);
        }

        take = helper(word, k, curr + 1, curr);

        return (take + notTake);
    }

public:
    int possibleStringCount(string word, int k)
    {
        int n = word.length();

        if (n < k)
        {
            return -1;
        }

        return helper(word, k, -1, -1);
    }
};

int main()
{

    return 0;
}