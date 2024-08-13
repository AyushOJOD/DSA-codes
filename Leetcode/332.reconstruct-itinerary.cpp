#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;

        for (const auto &ticket : tickets)
        {
            string u = ticket[0];
            string v = ticket[1];

            adj[u].push(v);
        }

        vector<string> order;
        stack<string> st;
        st.push("JFK");

        while (!st.empty())
        {
            string src = st.top();

            if (adj[src].empty())
            {
                order.push_back(src);
                st.pop();
            }
            else
            {
                st.push(adj[src].top());
                adj[src].pop();
            }
        }

        reverse(order.begin(), order.end());

        return order;
    }
};

int main()
{

    return 0;
}