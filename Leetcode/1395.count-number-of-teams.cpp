class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int n = rating.size();
        if (n < 3)
            return 0;

        vector<int> left_smaller(n, 0), right_larger(n, 0);
        vector<int> left_larger(n, 0), right_smaller(n, 0);

        // Calculate left_smaller and left_larger
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (rating[j] < rating[i])
                    left_smaller[i]++;
                if (rating[j] > rating[i])
                    left_larger[i]++;
            }
        }

        // Calculate right_larger and right_smaller
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (rating[j] > rating[i])
                    right_larger[i]++;
                if (rating[j] < rating[i])
                    right_smaller[i]++;
            }
        }

        // Count increasing and decreasing subsequences of size 3
        int increasing = 0, decreasing = 0;
        for (int i = 0; i < n; ++i)
        {
            increasing += left_smaller[i] * right_larger[i];
            decreasing += left_larger[i] * right_smaller[i];
        }

        return increasing + decreasing;
    }
};