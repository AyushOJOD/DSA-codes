#include <bits/stdc++.h>
using namespace std;

class FoodRatings
{
public:
    unordered_map<string, vector<pair<int, string>>> cuisines_mp; // {cuisines -> [{ratings, foods}]}
    unordered_map<string, int> food_rating;                       //{food -> rating}

    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        int n = foods.size();

        for (int i = 0; i < n; i++)
        {
            cuisines_mp[cuisines[i]].push_back({ratings[i], foods[i]});
            food_rating[foods[i]] = ratings[i];
        }
    }

    void changeRating(string food, int newRating)
    {
    }

    string highestRated(string cuisine)
    {
    }
};

int main()
{

    return 0;
}