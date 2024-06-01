#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int> &bills)
{
    int fives = 0;
    for (int i = 0; i < bills.size(); i++)
    {
        if (bills[i] == 5)
        {
            fives++;
        }
        else
        {
            if (fives >= (bills[i] - 5) / 5)
            {
                fives -= (bills[i] - 5) / 5;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{

    vector<int> bills = {5, 5, 5, 10, 20};

    cout << lemonadeChange(bills);

    return 0;
}