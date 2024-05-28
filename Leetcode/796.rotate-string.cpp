#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal)
{
    if (s.size() != goal.size())
    {
        return false;
    }

    string conc = s + s;

    return conc.find(goal) != string::npos;
}

int main()
{

    return 0;
}