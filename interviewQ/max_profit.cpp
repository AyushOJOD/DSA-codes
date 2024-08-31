#include <bits/stdc++.h>
using namespace std;

int findMaximumProfit(vector<int> &category, vector<int> &price)
{
    int n = price.size();

    vector<pair<int, int>> product; // {price, category}

    for (int i = 0; i < n; i++)
    {
        product.push_back({price[i], category[i]});
    }

    sort(product.begin(), product.end());

    unordered_set<int> diffCat;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += product[i].first * (diffCat.size() + 1);
        diffCat.insert(product[i].second);
    }

    return sum;
}

int main()
{

    vector<int> category = {3, 2, 1, 3};
    vector<int> price = {2, 1, 4, 4};

    cout << findMaximumProfit(category, price);

    return 0;
}