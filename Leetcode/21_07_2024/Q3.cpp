#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOperations(string s)
    {
        int res = 0;
        bool one_occured = false;

        vector<int> binary;

        for (char &ch : s)
        {
            if (ch == '1')
            {
                one_occured = true;
                binary.push_back(1);
            }
            else if (ch == '0' && one_occured)
            {
                binary.push_back(0);
                one_occured = false;
            }
        }

        int ones = 0;

        for (int it : binary)
        {
            if (it == 1)
            {
                ones++;
            }
            else
            {
                res += ones;
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}
