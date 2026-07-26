// Link: https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(2001) fixed-size frequency arrays
// Approach: first pass counts theCnt = total distinct values in nums (the
// target distinct-count a "complete" subarray must hit). Then a standard
// two-pointer "at least K distinct" sliding window: expand right, and while
// the window has all theCnt distinct values present, every further extension
// of the right end also stays complete, so add (n-i) for the current left
// position and shrink from the left to look for the next valid left bound.
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        static constexpr const size_t theVals{2'001ull};
        int freq[theVals];
        namespace rng = std::ranges;
        rng::fill(freq, 0);
        int theCnt{};
        for (int i : nums) {
            ++freq[i];
            theCnt += !(1 - freq[i]);
        }
        int i{}, j{}, ret{}, c{};
        int dp[theVals]{};
        const auto n{static_cast<int>(ranges::size(nums))};
        while (i < n) {
            ++dp[nums[i]];
            if (!(1 - dp[nums[i]]))
                ++c;
            while (c == theCnt) {
                ret += n - i;
                --dp[nums[j]];
                if (!dp[nums[j++]])
                    --c;
            }
            ++i;
        }
        return ret;
    }
};
