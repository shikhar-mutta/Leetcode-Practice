// Link: https://leetcode.com/problems/subarray-sum-equals-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: running prefix sum with a hashmap of prefix-sum counts;
// subarrays summing to k correspond to (prefix - k) seen before
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> count{{0, 1}};
        long long sum = 0;
        int total = 0;
        for (int x : nums) {
            sum += x;
            auto it = count.find(sum - k);
            if (it != count.end()) total += it->second;
            count[sum]++;
        }
        return total;
    }
};
