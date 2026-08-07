// Link: https://leetcode.com/problems/contiguous-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: treat 0 as -1, track running balance; same balance seen twice
// means the subarray between has equal 0s and 1s
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> firstIdx{{0, -1}};
        int balance = 0, best = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            balance += nums[i] == 1 ? 1 : -1;
            if (firstIdx.count(balance)) best = max(best, i - firstIdx[balance]);
            else firstIdx[balance] = i;
        }
        return best;
    }
};
