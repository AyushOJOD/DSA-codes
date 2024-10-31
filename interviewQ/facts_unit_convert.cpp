#include <bits/stdc++.h>
using namespace std;

// {"1 meter = 3.28 feet", "1 foot = 12 inches", "1 hour = 60 minutes", "1 minute = 60 seconds"}

class Solution
{
public:
    unordered_map<string, unordered_map<double, string>> graph;

    void parse_facts(string from, string to, double factor)
    {
        graph[from][to] = factor;
        graph[to][from] = 1.0 / factor;
    }

    string convert(string from, string to, double value)
    {
        if (graph.find(from) == graph.end() || graph.find(to) == graph.end())
        {
            return "Not convertible!";
        }

        queue<pair<string, double>> q;
        unordered_set<string> vis;
        q.push({from, value});
        vis.insert(from);

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            string currUnit = curr.first;
            double currValue = curr.second;

            if (currUnit == to)
            {
                return to_string(currValue);
            }

            for (auto &it : graph[currUnit])
            {
                if (vis.find(it.first) != vis.end())
                {
                    vis.insert(it.first);
                    q.push({it.first, currValue * it.second});
                }
            }
        }

        return "Not convertible!";
    }
};

int main()
{
    Solution obj;

    obj.parse_facts("meter", "feet", 3.28);
    obj.parse_facts("foot", "inches", 12);
    obj.parse_facts("hour", "minute", 60);
    obj.parse_facts("minute", "second", 60);

    cout << obj.convert("hour", "second", 1.0);

    return 0;
}