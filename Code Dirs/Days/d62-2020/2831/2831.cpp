// Link: https://leetcode.com/problems/find-the-longest-equal-subarray/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n) for the frequency counts
// Approach: sliding window where a window is valid if (window size - count of
// its most frequent value) <= k, i.e. at most k non-matching elements can be
// deleted to make the rest equal. maxFreq never needs to decrease when
// shrinking (a window that was valid at some maxFreq stays a valid candidate
// size even if a later window's maxFreq is lower), so track the running max
// and return it directly.
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {

        int n = nums.size();
        int maxFreq = 0, left = 0;

        vector<int> cnt(n + 1, 0);

        for (int right = 0; right < n; right++) {
            cnt[nums[right]]++;

            maxFreq = max(maxFreq, cnt[nums[right]]);

            int currWindowSize = right - left + 1;

            if (currWindowSize - maxFreq > k) {
                cnt[nums[left]]--;
                left++;
            }
        }

        return maxFreq;
    }
};
