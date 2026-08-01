// Link: https://leetcode.com/problems/k-th-smallest-remaining-even-integer-in-subarray-queries/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n + q log n)  SC: O(n)
// Approach: nums is strictly increasing, so its even-valued elements form
// a value-sorted subsequence; take the infinite sequence of positive evens
// 2,4,6,... and remove every even VALUE present in nums[l..r], then find
// the k-th smallest survivor. Binary search the index x in [l,r] (values
// sorted) for the boundary where "count of evens <= nums[x] still short of
// k after removal" flips, using a prefix count of even values; the answer
// is 2*(k + evens removed up to that boundary).
class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + (nums[i] % 2 == 0 ? 1 : 0);

        auto binarySearchRight = [&](int left, int right, function<bool(int)> check) {
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (!check(mid)) right = mid - 1;
                else left = mid + 1;
            }
            return right;
        };

        vector<int> ans(queries.size());
        for (size_t i = 0; i < queries.size(); i++) {
            long long l = queries[i][0], r = queries[i][1], k = queries[i][2];
            auto check = [&](int x) {
                return (long long)(nums[x] / 2) < k + (prefix[x+1] - prefix[l]);
            };
            int idx = binarySearchRight((int)l, (int)r, check);
            long long val = 2 * (k + (prefix[idx+1] - prefix[l]));
            ans[i] = (int)val;
        }
        return ans;
    }
};
