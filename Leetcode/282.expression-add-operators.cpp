#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void helper(int idx, string path, long resSoFar, long prevNum, string num, int target, vector<string> &ans)
    {
        if (idx == num.length())
        {
            if (resSoFar == target)
            {
                ans.push_back(path);
                return;
            }
        }

        for (int j = idx; j < num.length(); j++)
        {
            if (j > idx && num[idx] == '0')
            {
                break;
            }
            long currValue = stol(num.substr(i, j - i + 1));

            if (i == 0)
            {
                helper(j + 1, path + currValue, currValue, currValue, num, target, ans);
            }
            else
            {
                helper(j + 1, path + '+' + currValue, resSoFar + currValue, currValue, num, target, ans);
                helper(j + 1, path + '+' + currValue, resSoFar - currValue, -currValue, num, target, ans);
                helper(j + 1, path + '*' + currValue, resSoFar - prevNum + prevNum * currValue, prevNum * currValue, num, target, ans);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target)
    {
        vector<string> ans;
        helper(0, "", 0, 0, num, target, ans);

        return ans;
    }
};

int main()
{

    return 0;
}