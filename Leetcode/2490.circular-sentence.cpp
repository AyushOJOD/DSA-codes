#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isCircularSentence(string sentence)
    {
        int n = sentence.length();

        bool isCircular = true;

        for (int i = 0; i < n; i++)
        {
            if (sentence[i] == " ")
            {
                if (sentence[i - 1] != sentence[i + 1])
                {
                    isCircular = false;
                    break;
                }
            }
        }

        if (sentence[0] != sentence[n - 1])
        {
            isCircular = false;
        }

        return isCircular;
    }
};

int main()
{

    return 0;
}