#include <bits/stdc++.h>
using namespace std;

string largestMagical(string binString)
{
    if (binString.empty())
        return binString;
    vector<string> substrings;
    int balanceCount = 0, startIdx = 0;
    for (int currIdx = 0; currIdx < binString.size(); ++currIdx)
    {
        balanceCount += binString[currIdx] == '1' ? 1 : -1;
        if (balanceCount == 0)
        {
            substrings.push_back("1" + largestMagical(binString.substr(startIdx + 1, currIdx - startIdx - 1)) + "0");
            startIdx = currIdx + 1;
        }
    }
    sort(substrings.begin(), substrings.end(), greater<string>());
    return accumulate(substrings.begin(), substrings.end(), string{});
}

int main()
{

    string s;
    cin >> s;

    cout << largestMagical(s) << endl;

    return 0;
}
