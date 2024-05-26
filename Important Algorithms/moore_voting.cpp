#include <bits/stdc++.h>
using namespace std;
// Moore's Voting Algorithm is used to find the majority element in an array.

int majoriyElement(vector<int> &nums)
{
    int count = 0;
    int candidate = 0;
    for (int num : nums)
    {
        if (count == 0) // if count is 0, then we have a new candidate
        {
            candidate = num;
        }
        if (num == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return candidate;
}

int main()
{

    return 0;
}