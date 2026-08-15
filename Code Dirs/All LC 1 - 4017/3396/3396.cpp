// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        for (int start = 0; start <= n; start += 3) {
            unordered_set<int> seen;
            bool ok = true;
            for (int i = start; i < n; i++) {
                if (!seen.insert(nums[i]).second) { ok = false; break; }
            }
            if (ok) return start / 3;
        }
        return (n + 2) / 3;
    }
};
