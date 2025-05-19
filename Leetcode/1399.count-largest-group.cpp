/*
 * @lc app=leetcode id=1399 lang=cpp
 *
 * [1399] Count Largest Group
 *
 * https://leetcode.com/problems/count-largest-group/description/
 *
 * algorithms
 * Easy (66.75%)
 * Likes:    603
 * Dislikes: 1094
 * Total Accepted:    97.8K
 * Total Submissions: 135.2K
 * Testcase Example:  '13'
 *
 * You are given an integer n.
 *
 * Each number from 1 to n is grouped according to the sum of its digits.
 *
 * Return the number of groups that have the largest size.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 13
 * Output: 4
 * Explanation: There are 9 groups in total, they are grouped according sum of
 * its digits of numbers from 1 to 13:
 * [1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
 * There are 4 groups with largest size.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 2
 * Output: 2
 * Explanation: There are 2 groups [1], [2] of size 1.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10^4
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
private:
    int sumOfDigits(int num)
    {
        int sum = 0;

        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

public:
    int countLargestGroup(int n)
    {
        unordered_map<int, int> mp;

        for (int i = 1; i <= n; i++)
        {
            int sum = sumOfDigits(i);
            mp[sum]++;
        }

        int maxGroup = INT_MIN;

        for (auto &[k, v] : mp)
        {
            maxGroup = max(maxGroup, v);
        }

        int cnt = 0;

        for (auto &[k, v] : mp)
        {
            if (v == maxGroup)
            {
                cnt++;
            }
        }

        return cnt;
    }
};

int main()
{

    return 0;
}

// @lc code=end
