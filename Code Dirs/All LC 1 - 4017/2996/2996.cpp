// Link: https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        while (i < n && nums[i] == nums[i-1] + 1) i++;
        long long sum = 0;
        for (int j = 0; j < i; j++) sum += nums[j];
        unordered_set<long long> present(nums.begin(), nums.end());
        while (present.count(sum)) sum++;
        return (int)sum;
    }
};
