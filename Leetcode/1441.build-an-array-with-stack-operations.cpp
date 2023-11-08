#include <bits/stdc++.h>
using namespace std;

vector<string> buildArray(vector<int> &target, int n)
{
    int count;
    int size = target.size();
    string push = "Push";
    string pop = "Pop";
    int final = target[size - 1];
    int curr = 0;

    vector<string> result;

    for (int i = 1; i <= final; i++)
    {
        count = target[curr];
        if (i == count)
        {
            result.push_back(push);
            curr++;
        }
        else
        {
            result.push_back(push);
            result.push_back(pop);
        }
    }

    return result;
}

int main()
{

    return 0;
}