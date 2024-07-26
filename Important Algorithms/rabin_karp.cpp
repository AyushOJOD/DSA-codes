#include <bits/stdc++.h>
using namespace std;

// Rabin Karp Algorithm
// Given a text and a pattern, we have to find whether the pattern is present in the text or not.

// Time Complexity: O(n+m)
// Space Complexity: O(1)

// The idea is to use hashing to compare the pattern with the text. We calculate the hash of the pattern and then calculate the hash of the text for the first m characters. Then we compare the hash of the pattern with the hash of the text. If they are equal, then we compare the pattern with the text character by character. If they are not equal, then we calculate the hash of the next m characters and compare it with the hash of the pattern. We keep doing this until we find the pattern in the text or we reach the end of the text.

bool isPresent(string s, string t)
{
    int target_hash = 0;

    for (int i = 0; i < t.length(); i++)
    {
        target_hash += (t[i] - 'a');
    }

    int source_hash = 0;

    for (int i = 0; i < t.length(); i++)
    {
        source_hash += s[i];
    }

    bool isFound = tr;

    if (source_hash == target_hash)
    {
        for (int i = 0; i < t.length(); i++)
        {
            if (s[i] != t[i])
            {
                break;
            }
        }

        return true;
    }

    for (int i = t.length(); i < s.length(); i++)
    {
        source_hash = source_hash - s[i - t.length()] + s[i];
    }
}

int main()
{

    return 0;
}