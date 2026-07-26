// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * log(maxVal)) for the shortest-GCD-1-subarray scan
// SC: O(1)
// Approach: replacing adjacent pair (a,b) with gcd(a,b) is the only op, so a
// 1 can only ever be created from a contiguous subarray whose GCD is 1 (via
// minLen-1 ops), then spread to every other position (1 op each). If nums
// already has ones, just spread the cheapest one (n-ones ops). Otherwise find
// the shortest subarray with GCD 1 (impossible -> overall GCD != 1 -> -1).
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);

        if (ones > 0)
            return n - ones; // spread existing 1s to all other positions

        // find the shortest subarray with GCD == 1
        int minLen = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int g = nums[i];
            for (int j = i + 1; j < n; ++j) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    minLen = min(minLen, j - i + 1);
                    break; // shorter subarrays starting later may still win
                }
            }
        }

        if (minLen == INT_MAX)
            return -1; // overall GCD != 1: impossible

        // (minLen - 1) ops to create one 1, then (n - 1) ops to spread it
        return (minLen - 1) + (n - 1);
    }

private:
    int gcd(int a, int b) {
        while (b) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
};
