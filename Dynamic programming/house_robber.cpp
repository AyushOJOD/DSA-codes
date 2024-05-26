// Mr.X is a professional robber planning to rob houses along a street.Each house has a certain amount of money hidden.

// All houses along this street are arranged in a circle.That means the first house is the neighbour of the last one.
// Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses are broken into on the same night.

// You are given an array /
// list of non -
// negative integers 'ARR' representing the amount of money of each house.Your task is to return the maximum amount of money Mr.X can rob tonight without alerting the police.

#include <bits/stdc++.h>
using namespace std;

long long int houseRobber(vector<int> &valueInHouse)
{
    // Write your code here.

    int n = valueInHouse.size();
    vector<int> temp1, temp2;

    if (n == 1)
    {
        return valueInHouse[0];
    }

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(valueInHouse[i]); // does not include the first element
        if (i != n - 1)
            temp2.push_back(valueInHouse[i]); // does not include the last element
    }

    return max(f(temp1), f(temp2));
}

long long f(vector<int> &temp)
{
    int n = temp.size();

    long long int prev = temp[0];
    long long int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        long long int pick = temp[i];
        if (i > 1)
        {
            pick += prev2;
        }

        long long int notPick = prev;

        long long int curr = max(pick, notPick);

        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int main()
{

    return 0;
}