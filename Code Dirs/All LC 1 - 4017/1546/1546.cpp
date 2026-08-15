// Link: https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<int> seen;
        seen.insert(0);
        int sum = 0, count = 0;
        for (int x : nums) {
            sum += x;
            if (seen.count(sum - target)) {
                count++;
                seen.clear();
                seen.insert(0);
                sum = 0;
            } else {
                seen.insert(sum);
            }
        }
        return count;
    }
};
