// Link: https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)
// SC: O(n)
// Approach: walk i from right to left; maintain a sorted set of every
// nums[j] with j >= i+x (elements far enough ahead to be a valid partner),
// inserting nums[i+x] each step before querying. For each i, binary-search
// the set for the closest value(s) to nums[i] via lower_bound and its
// predecessor, updating the running minimum absolute difference.
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();

        if (x == 0)
            return 0;

        set<int> st;
        int ans = INT_MAX;

        for (int i = n - 1 - x; i >= 0; i--) {
            st.insert(nums[i + x]);

            auto it = st.lower_bound(nums[i]);

            if (it != st.end())
                ans = min(ans, abs(nums[i] - *it));

            if (it != st.begin()) {
                --it;
                ans = min(ans, abs(nums[i] - *it));
            }
        }

        return ans;
    }
};
