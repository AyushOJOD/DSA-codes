#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A)
{
    unordered_map<int, int> mp; // {num, idx}

    for (int i = 0; i < A.size(); i++)
    {
        if (mp.find(A[i]) != mp.end())
        {
            // Duplicate found, increment the number at its first occurrence
            int idx = mp[A[i]];
            mp.erase(A[i]);
            A[idx]++; // Increment the first occurrence
            mp[A[idx]] = idx;
        }
        // Always update the map with the current index
        mp[A[i]] = i;
    }

    // Priority queue to sort elements by their indices
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (auto it : mp)
    {
        pq.push({it.second, it.first});
    }

    vector<int> res;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        res.push_back(it.second);
    }

    return res;
}

int main()
{
    vector<int> A = {1, 1, 2, 2};
    vector<int> result = solve(A);

    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
