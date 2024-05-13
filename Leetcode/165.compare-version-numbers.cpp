#include <bits/stdc++.h>
using namespace std;

int compareVersion(string version1, string version2)
{
    vector<int> v1, v2;
    string temp = "";

    for (auto it : version1)
    {
        if (it == '.')
        {
            v1.push_back(stoi(temp));
            temp = "";
        }
        else
        {
            temp += it;
        }
    }

    for (auto it : version2)
    {
        if (it == '.')
        {
            v2.push_back(stoi(temp));
            temp = "";
        }
        else
        {
            temp += it;
        }
    }

    
}

int main()
{

    return 0;
}