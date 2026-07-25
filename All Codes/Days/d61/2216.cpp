// Link: https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: greedily scan left to right tracking each element's position in
// the array-after-deletions-so-far (i - deletions). Whenever that position
// is even (would become an odd-indexed partner, i.e. nums[2k]) and it
// equals the next element, deleting the current one breaks the illegal
// equal pair. Finally, if the total kept length is odd, one more deletion
// is needed to make it even.
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size(), deletions = 0;
        int i = 0;
        while (i < n) {
            int keptIndex = i - deletions; // position in the resulting array
            if (keptIndex % 2 == 0 && i + 1 < n && nums[i] == nums[i + 1]) {
                ++deletions; // delete nums[i], breaks the equal pair
            }
            ++i;
        }
        // resulting length must be even
        if ((n - deletions) % 2)
            ++deletions;
        return deletions;
    }
};
