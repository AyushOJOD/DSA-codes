#include <bits/stdc++.h>
using namespace std;

class RandomizedCollection
{
public:
    vector<int> v;
    unordered_map<int, int> mp;
    RandomizedCollection()
    {
    }

    bool insert(int val)
    {
        if (mp[val] == 0)
        {
            v.push_back(val);
            mp[val]++;
            return true;
        }
        else if (mp[val] > 0)
        {
            v.push_back(val);
            mp[val]++;
            return false;
        }
        return false;
    }

    bool remove(int val)
    {
        if (mp[val] > 0)
        {
            auto it = find(v.begin(), v.end(), val);
            v.erase(it);
            mp[val]--;
            return true;
        }
        return false;
    }

    int getRandom()
    {
        return v[rand() % v.size()];
    }
};

int main()
{

    return 0;
}