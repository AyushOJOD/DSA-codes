#include <bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int> &arr)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }

    unordered_set<int> st;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (st.find(it->second) != st.end())
        {
            return false;
        }
        st.insert(it->second);
    }

    return true;
}

int main()
{

    vector<int> arr = {1, 2, 2, 1, 1, 3};

    cout << uniqueOccurrences(arr) << endl;

    return 0;
}