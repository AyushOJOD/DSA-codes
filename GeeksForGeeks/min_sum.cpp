#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addStrings(const string &num1, const string &num2)
    {
        string result;
        int carry = 0, i = num1.size() - 1, j = num2.size() - 1;

        while (i >= 0 || j >= 0 || carry > 0)
        {
            int sum = carry;
            if (i >= 0)
                sum += num1[i--] - '0';
            if (j >= 0)
                sum += num2[j--] - '0';
            result.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        reverse(result.begin(), result.end());
        return result;
    }

    string minSum(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
        {
            return to_string(arr[0]);
        }

        sort(arr.begin(), arr.end());

        string num1, num2;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                num1 += to_string(arr[i]);
            }
            else
            {
                num2 += to_string(arr[i]);
            }
        }

        return addStrings(num1, num2);
    }
};

int main()
{

    return 0;
}