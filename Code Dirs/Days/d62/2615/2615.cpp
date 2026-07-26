// Link: https://leetcode.com/problems/sum-of-distances/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n) for the per-value index groups
// Approach: group indices by value (only equal-value pairs contribute to the
// answer). Within each group's sorted index list, for the k-th index i, the sum
// of distances to the k indices on its left is k*i - leftSum, and to the
// (m-1-k) indices on its right is rightSum - (m-1-k)*i, where leftSum/rightSum
// are running prefix/suffix sums of indices in the group.
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; ++i)
            groups[nums[i]].push_back(i);

        vector<long long> res(n, 0);
        for (auto& [val, idx] : groups) {
            int m = idx.size();
            long long total = 0;
            for (int x : idx)
                total += x;

            long long leftSum = 0;
            for (int k = 0; k < m; ++k) {
                long long i = idx[k];
                long long rightSum = total - leftSum - i;
                // distances to the k elements on the left + (m-1-k) on the
                // right
                long long left = (long long)k * i - leftSum;
                long long right = rightSum - (long long)(m - 1 - k) * i;
                res[idx[k]] = left + right;
                leftSum += i;
            }
        }
        return res;
    }
};
