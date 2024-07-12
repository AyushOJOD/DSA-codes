#include <bits/stdc++.h>
using namespace std;

class LRUCache
{

public:
    list<int> dll;
    map<int, pair<list<int>::iterator, int>> mp;
    int n;

    LRUCache(int capacity)
    {
        n = capacity;
    }

    void mostRecentlyUsed(int key)
    {
        dll.erase(mp[key].first);

        dll.push_front(key);

        mp[key].first = dll.begin();
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }

        int value = mp[key].second;

        mostRecentlyUsed(key);

        return value;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            mp[key].second = value;
            mostRecentlyUsed(key);
        }

        dll.push_front(key);
        mp[key] = {dll.begin(), value};
        n--;

        if (n < 0)
        {
            int del_idx = dll.end();
            mp.erase(del_idx);
            dll.pop_back();

            n++;
        }
    }
};

int main()
{

    return 0;
}