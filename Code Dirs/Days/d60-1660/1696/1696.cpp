// Link: https://leetcode.com/problems/jump-game-vi/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the length of the input array.
// SC: O(n) for storing the dp array and deque.
// Approach:
//    1. Create a dp array to store the maximum score at each index.
//    2. Initialize the first element of dp with the first element of nums.
//    3. Create a deque to store the indices of the maximum scores within the last k indices.
//    4. Iterate through the nums array starting from index 1.
//    5. For each index, remove indices from the front of the deque that are out of the current window of size k.
//    6. Update the dp value at the current index with the maximum score from the front of the deque plus the current nums value.
//    7. Remove indices from the back of the deque while the dp value at those indices is less than or equal to the current dp value, as they are no longer useful for future calculations.
//    8. Push the current index to the back of the deque.
//    9. Return the last element of the dp array, which contains the maximum score to reach the last index.
class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> dp(n);

        dp[0] = nums[0];

        deque<int> dq;
        dq.push_back(0);

        for (int i = 1; i < n; i++)
        {

            while (!dq.empty() && dq.front() < i - k)
                dq.pop_front();

            dp[i] = dp[dq.front()] + nums[i];

            while (!dq.empty() && dp[dq.back()] <= dp[i])
                dq.pop_back();

            dq.push_back(i);
        }

        return dp[n - 1];
    }
};
