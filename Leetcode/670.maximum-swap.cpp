#include <bits/stdc++.h>
using namespace std;

// 1. num = 2736
// maxNum = 7632

// 2. num = 9973
// maxNum = 9793

class Solution
{
public:
    int maximumSwap(int num)
    {
        string curr = to_string(num);
        string maxNum = to_string(num);

        sort(maxNum.begin(), maxNum.end(), greater<char>());

        int idx = 0;

        while (idx < curr.length() && curr[idx] == maxNum[idx])
        {
            idx++;
        }

        if (idx == curr.length())
        {
            return num;
        }

        for (int i = 0; i < curr.size(); i++)
        {
            if (curr[i] == maxNum[idx])
            {
                swap(curr[idx], curr[i]);
                break;
            }
        }

        return stoi(curr);
    }
};

int main()
{

    int num;
    cin >> num;

    Solution obj;

    cout << obj.maximumSwap(num) << endl;

    return 0;
}