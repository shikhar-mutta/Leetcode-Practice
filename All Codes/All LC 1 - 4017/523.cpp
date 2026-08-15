// Link: https://leetcode.com/problems/continuous-subarray-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(min(n,k))
// Approach: track running sum mod k, if the same remainder appears at
// indices at least 2 apart, the subarray between sums to a multiple of k
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> firstIdx{{0, -1}};
        int sum = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            sum += nums[i];
            int rem = k != 0 ? sum % k : sum;
            if (firstIdx.count(rem)) {
                if (i - firstIdx[rem] >= 2) return true;
            } else {
                firstIdx[rem] = i;
            }
        }
        return false;
    }
};
