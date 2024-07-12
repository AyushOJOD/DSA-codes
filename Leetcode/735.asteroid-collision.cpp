#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;
        int n = asteroids.size();
        st.push(asteroids[n - 1]);
        int idx = n - 2;

        while (idx >= 0)
        {
            if (st.empty())
            {
                st.push(asteroids[idx]);
            }
            else if (st.top() < 0 && asteroids[idx] > 0)
            {
                if (abs(st.top()) < abs(asteroids[idx]))
                {
                    st.pop();
                    idx++;
                }
                else if (abs(st.top()) == abs(asteroids[idx]))
                {
                    st.pop();
                }
            }
            else
            {
                st.push(asteroids[idx]);
            }
            idx--;
        }

        vector<int> ans;

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};

int main()
{

    return 0;
}