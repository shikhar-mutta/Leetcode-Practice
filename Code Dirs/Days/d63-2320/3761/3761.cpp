// Link: https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: a mirror pair is an ordered (i<j) with reverse(nums[i]) ==
// nums[j], where reverse drops trailing-zero digits like normal integer
// reversal (so 120 -> 21, not symmetric back). Scan left to right; before
// processing index k, check whether some earlier index already stored
// its reverse equal to nums[k] (map keyed by reverse(nums[i]) -> most
// recent index, which minimizes the distance for future matches), then
// record reverse(nums[k]) -> k for later lookups.
class Solution {
    long long reverseNum(long long x) {
        long long rev = 0;
        while (x > 0) { rev = rev * 10 + x % 10; x /= 10; }
        return rev;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<long long, int> lastIdx;
        int ans = INT_MAX;
        for (int k = 0; k < (int)nums.size(); k++) {
            auto it = lastIdx.find(nums[k]);
            if (it != lastIdx.end()) ans = min(ans, k - it->second);
            lastIdx[reverseNum(nums[k])] = k;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
