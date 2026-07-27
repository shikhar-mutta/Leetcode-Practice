// Link: https://leetcode.com/problems/count-bowl-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: every bowl subarray [l,r] has a unique interior argmax j,
// and one can show l must be exactly j's nearest-greater-to-the-left
// (PGE) and r exactly its nearest-greater-to-the-right (NGE) — anything
// else in between j and a farther boundary would itself exceed nums[j],
// contradicting that j is the argmax, or would violate the endpoint-vs-
// interior comparison. So each index j with BOTH a PGE and an NGE
// contributes exactly one bowl subarray; count such j via two monotonic
// stack passes.
class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<bool> hasPGE(n, false), hasNGE(n, false);

        vector<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && nums[stk.back()] < nums[i]) stk.pop_back();
            hasPGE[i] = !stk.empty();
            stk.push_back(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && nums[stk.back()] < nums[i]) stk.pop_back();
            hasNGE[i] = !stk.empty();
            stk.push_back(i);
        }

        long long count = 0;
        for (int i = 0; i < n; i++) if (hasPGE[i] && hasNGE[i]) count++;
        return count;
    }
};
