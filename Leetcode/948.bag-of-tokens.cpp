#include <bits/stdc++.h>
using namespace std;

int bagOfTokensScore(vector<int> &tokens, int power)
{
    int score = 0;

    int left = 0, right = tokens.size() - 1, maxScore = 0;

    sort(tokens.begin(), tokens.end());

    while (left <= right)
    {
        if (power >= tokens[left])
        {
            power -= tokens[left];
            score++;
            left++;
            maxScore = max(maxScore, score);
        }
        else if (score > 0)
        {
            power += tokens[right];
            right--;
            score--;
        }
        else
        {
            break;
        }
    }

    return maxScore;
}

int main()
{
    vector<int> tokens = {100, 200, 300, 400};
    int power = 200;

    cout << bagOfTokensScore(tokens, power) << endl;

    return 0;
}