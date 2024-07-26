#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> getNSI(vector<int> &A)
    {
        stack<int> st;
        st.push(0);

        vector<int> NSI(A.size(), -1);

        for (int i = 1; i < A.size(); i++)
        {
            while (!st.empty() && A[st.top()] > A[i])
            {
                NSI[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        return NSI;
    }

    vector<int> getPSI(vector<int> &A)
    {
        stack<int> st;
        st.push(A.size() - 1);

        vector<int> PSI(A.size(), -1);

        for (int i = A.size() - 2; i >= 0; i--)
        {
            while (!st.empty() && A[st.top()] > A[i])
            {
                PSI[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        return PSI;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> NSI = getNSI(heights);
        vector<int> PSI = getPSI(heights);

        int maxArea = INT_MIN;
        int n = heights.size();

        for (int i = 0; i < n; i++)
        {

            int next_smaller = (NSI[i] != -1) ? NSI[i] : heights.size();
            int prev_smaller = (PSI[i] != -1) ? PSI[i] : -1;

            int length = (next_smaller - i) + (i - prev_smaller) - 1;
            int width = heights[i];

            int area = length * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

int main()
{

    return 0;
}