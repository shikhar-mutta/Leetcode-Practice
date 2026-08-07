// Link: https://leetcode.com/problems/range-sum-query-mutable/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) update/query, O(n log n) construct  SC: O(n)
// Approach: Fenwick tree (BIT) for point update + prefix sum query
class NumArray {
    vector<int> nums;
    vector<int> tree;
    int n;

    void add(int i, int delta) {
        for (i++; i <= n; i += i & (-i)) tree[i] += delta;
    }

    int prefixSum(int i) {
        int sum = 0;
        for (i++; i > 0; i -= i & (-i)) sum += tree[i];
        return sum;
    }

public:
    NumArray(vector<int>& nums) : nums(nums), n(nums.size()) {
        tree.assign(n + 1, 0);
        for (int i = 0; i < n; i++) add(i, nums[i]);
    }

    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;
        add(index, delta);
    }

    int sumRange(int left, int right) {
        return prefixSum(right) - (left > 0 ? prefixSum(left - 1) : 0);
    }
};
