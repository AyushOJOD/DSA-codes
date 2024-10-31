#include <iostream>
#include <deque>
#include <vector>
#include <climits>

using namespace std;

// Function to find the minimum of the maximums in all windows of size w
int min_of_max_sliding_window(const vector<int> &traffic, int w)
{
    deque<int> dq;
    int n = traffic.size();
    vector<int> max_in_window;

    // Process the first window of size w
    for (int i = 0; i < w; ++i)
    {
        // Remove all elements smaller than the current element from the deque
        while (!dq.empty() && traffic[dq.back()] <= traffic[i])
        {
            dq.pop_back();
        }
        // Add the current element's index
        dq.push_back(i);
    }

    // Add the max for the first window
    max_in_window.push_back(traffic[dq.front()]);

    // Process the remaining elements
    for (int i = w; i < n; ++i)
    {
        // Remove elements that are out of this window
        while (!dq.empty() && dq.front() <= i - w)
        {
            dq.pop_front();
        }

        // Remove all elements smaller than the current element from the deque
        while (!dq.empty() && traffic[dq.back()] <= traffic[i])
        {
            dq.pop_back();
        }

        // Add the current element's index
        dq.push_back(i);

        // Add the max for this window
        max_in_window.push_back(traffic[dq.front()]);
    }

    // Find and return the minimum of the maximums
    int min_max = INT_MAX;
    for (int val : max_in_window)
    {
        min_max = min(min_max, val);
    }

    return min_max;
}

int main()
{
    // Read the full test case at once
    int n, q;
    cin >> n >> q;

    vector<int> traffic(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> traffic[i];
    }

    // Process each query and print results at once
    vector<int> results;
    for (int i = 0; i < q; ++i)
    {
        int w;
        cin >> w;
        results.push_back(min_of_max_sliding_window(traffic, w));
    }

    // Output all results in one go
    for (int result : results)
    {
        cout << result << endl;
    }

    return 0;
}
