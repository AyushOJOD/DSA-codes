#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
        {
            return "0";
        }

        string s = "";

        if (numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0)
        {
            s.append("-");
        }

        ll divisor = abs(static_cast<ll>(denominator));
        ll dividend = abs(static_cast<ll>(numerator));

        ll quotient = (dividend / divisor);
        ll remainder = dividend % divisor;

        s.append(quotient);

        if (remainder == 0)
        {
            return s;
        }

        s.append(".");

        unordered_map<ll, int> mp;

        while (remainder != 0)
        {
            if (mp.find(remainder) != mp.end())
            {
                s.insert(mp[remainder], '(');
                s += ')';
                break;
            }

            mp[remainder] = s.length();
        }

        return s;
    }
};

int main()
{

    return 0;
}