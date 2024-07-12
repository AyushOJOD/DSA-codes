#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution
{
private:
    void solve(ll n, vector<char> &evenPlaces, vector<char> &oddPlaces, int idx, string &curr, int &res)
    {
        if (idx == n)
        {
            res++;
            return; // Return to avoid further processing
        }

        if (idx % 2 == 0) // even places
        {
            for (int j = 0; j < evenPlaces.size(); j++)
            {
                curr.push_back(evenPlaces[j]);
                solve(n, evenPlaces, oddPlaces, idx + 1, curr, res);
                curr.pop_back();
            }
        }
        else // odd places
        {
            for (int j = 0; j < oddPlaces.size(); j++)
            {
                curr.push_back(oddPlaces[j]);
                solve(n, evenPlaces, oddPlaces, idx + 1, curr, res);
                curr.pop_back();
            }
        }
    }

public:
    int countGoodNumbers(long long n)
    {
        vector<char> evenPlaces = {'0', '2', '4', '6', '8'};
        vector<char> oddPlaces = {'2', '3', '5', '7'};

        int res = 0;
        string curr;

        solve(n, evenPlaces, oddPlaces, 0, curr, res);

        return res % 1000000007;
    }
};

int main()
{

    return 0;
}