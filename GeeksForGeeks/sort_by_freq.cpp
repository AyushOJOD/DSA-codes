#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortByFreq(vector<int> &arr)
    {
        unordered_map<int, int> freqMap;
        int n = arr.size();

        // Count the frequency of each element
        for (int num : arr)
        {
            freqMap[num]++;
        }

        // Create a vector of pairs (element, frequency)
        vector<pair<int, int>> freqArr;
        for (auto &entry : freqMap)
        {
            freqArr.push_back(entry);
        }

        // Sort by frequency (descending), and by value (ascending) for ties
        sort(freqArr.begin(), freqArr.end(), [](pair<int, int> a, pair<int, int> b)
             {
                 if (a.second != b.second)
                     return a.second > b.second;
                 return a.first < b.first; });

        // Rebuild the array based on the sorted frequencies
        vector<int> result;
        for (auto &entry : freqArr)
        {
            result.insert(result.end(), entry.second, entry.first);
        }

        return result;
    }
};

int main()
{

    return 0;
}