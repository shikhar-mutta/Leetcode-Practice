// Link: https://leetcode.com/problems/partition-array-into-k-distinct-groups/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: n must be divisible by k (giving n/k groups of size k), and
// each group can contain a given value at most once, so no value's
// frequency may exceed n/k.
class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false;
        int groups = n / k;
        unordered_map<int, int> freq;
        for (int x : nums) if (++freq[x] > groups) return false;
        return true;
    }
};
