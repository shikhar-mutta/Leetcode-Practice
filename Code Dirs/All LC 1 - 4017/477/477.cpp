// Link: https://leetcode.com/problems/total-hamming-distance/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(32n)  SC: O(1)
// Approach: for each bit position, count how many numbers have it set;
// ones*zeros pairs each contribute 1 to the total hamming distance
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        for (int bit = 0; bit < 32; bit++) {
            int ones = 0;
            for (int x : nums) if (x & (1 << bit)) ones++;
            total += (long long)ones * (n - ones);
        }
        return (int)total;
    }
};
