// Link: https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n)
// Approach: dp[i] = whether nums[0..i] can be validly partitioned. Ending
// at index i, the last group is either a pair of equal elements (checked
// against dp[i-2]) - possibly itself an extension of a same-value triple
// (checked against dp[i-3]) - or a triple of consecutive increasing
// values (checked against dp[i-3]). dp[0] is false since a single element
// can never end a valid partition on its own.
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n);

        dp[0] = false;

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] == nums[i]) {
                if (i - 2 < 0 || dp[i - 2])
                    dp[i] = true;
                else if (nums[i - 2] == nums[i - 1] && (i - 3 < 0 || dp[i - 3]))
                    dp[i] = true;
                else
                    dp[i] = false;
            } else if (i - 2 >= 0 && nums[i - 2] + 1 == nums[i - 1] &&
                       nums[i - 1] + 1 == nums[i] && (i - 3 < 0 || dp[i - 3]))
                dp[i] = true;
            else
                dp[i] = false;
        }

        return dp[n - 1];
    }
};
