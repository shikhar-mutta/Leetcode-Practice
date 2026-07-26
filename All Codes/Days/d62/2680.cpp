// Link: https://leetcode.com/problems/maximum-or/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n) for the prefix/suffix OR arrays
// Approach: all k shifts must go to a single element (splitting them is never
// better since OR-ing in a doubled value never beats one fully-shifted value).
// So for each i, try shifting nums[i] left by k and OR it with the OR of all
// OTHER elements (prefix[i-1] | suffix[i+1]); take the best over all i.
class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> prefix(n), suffix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] | nums[i];
        }
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] | nums[i];
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long currOR = 0;
            if (i > 0) {
                currOR |= prefix[i - 1];
            }
            if (i < n - 1) {
                currOR |= suffix[i + 1];
            }
            long long shifted = (long long)nums[i] << k;
            ans = max(ans, shifted | currOR);
        }
        return ans;
    }
};
