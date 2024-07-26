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

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int maxAreaOnes = 0;
        vector<int> height(matrix[0].size(), 0);

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == '1')
                {
                    height[j] += 1;
                }
                else
                {
                    height[j] = 0;
                }
            }

            int currArea = largestRectangleArea(height);

            maxAreaOnes = max(maxAreaOnes, currArea);
        }

        return maxAreaOnes;
    }
};

int main()
{

    return 0;
}