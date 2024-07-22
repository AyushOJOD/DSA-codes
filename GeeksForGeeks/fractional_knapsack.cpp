#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

class Solution
{
private:
    bool static comp(Item a, Item b)
    {
        double unit1 = double(a.value) / double(a.weight);
        double unit2 = double(b.value) / double(b.weight);

        return unit1 > unit2;
    }

public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        sort(arr, arr + n, comp);

        double currValue = 0.0;

        for (int i = 0; i < n; i++)
        {
            if (w >= arr[i].weight)
            {
                currValue += arr[i].value;
                w -= arr[i].weight;
            }
            else
            {
                currValue += (double(arr[0].value) / double(arr[0].weight)) * w;
                break;
            }
        }
        return currValue;
    }
};

int main()
{

    return 0;
}