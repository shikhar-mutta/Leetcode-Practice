// Link: https://leetcode.com/problems/find-maximum-non-decreasing-array-length/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
//  Approach: We can use dynamic programming to find the maximum non-decreasing array length. We can maintain a prefix sum array P where P[i] stores the sum of nums[0...i-1]. We can also maintain a dp array where dp[j] stores the maximum non-decreasing array length ending at index j. We can also maintain a last array where last[j] stores the last element of the maximum non-decreasing array ending at index j. We can use a monotonic queue to find the largest i such that P[i] + last[i] <= P[j]. We can then update dp[j] and last[j] accordingly. We can also maintain the monotonic property of the queue by removing strictly worse candidates from the back. Finally, we can return dp[n].
class Solution
{
public:
    int findMaximumLength(vector<int> &nums)
    {
        int n = nums.size();

        // P[i] stores the sum of nums[0...i-1]
        vector<long long> P(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            P[i + 1] = P[i] + nums[i];
        }

        vector<int> dp(n + 1, 0);
        vector<long long> last(n + 1, 0);

        // Array-based monotonic queue storing indices
        vector<int> dq(n + 1, 0);
        int head = 0, tail = 1; // Initialize with index 0

        for (int j = 1; j <= n; ++j)
        {
            // Find the largest i such that P[i] + last[i] <= P[j]
            // We check head + 1 to ensure we don't pop the only valid element
            while (head + 1 < tail &&
                   P[dq[head + 1]] + last[dq[head + 1]] <= P[j])
            {
                head++;
            }

            int i = dq[head];

            // Transition state
            dp[j] = dp[i] + 1;
            last[j] = P[j] - P[i];

            long long W_j = P[j] + last[j];

            // Maintain monotonic property: remove strictly worse candidates
            // from the back
            while (head < tail && P[dq[tail - 1]] + last[dq[tail - 1]] >= W_j)
            {
                tail--;
            }

            // Add current index as a future candidate
            dq[tail++] = j;
        }

        return dp[n];
    }
};
