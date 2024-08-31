#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target)
    {
    }
};

int main()
{
    // Example usage
    Solution sol;
    vector<vector<int>> blocked = {{0, 1}, {1, 0}};
    vector<int> source = {0, 0};
    vector<int> target = {0, 2};

    bool result = sol.isEscapePossible(blocked, source, target);
    cout << (result ? "Escape possible" : "Escape not possible") << endl;

    return 0;
}
