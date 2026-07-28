// Link: https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2 + n*maxBits)  SC: O(maxVal)
// Approach: first compute freq[v] = number of (i,j) pairs with
// nums[i]&nums[j]==v (O(n^2)). Then for each such pair-AND value v and
// each element z in nums, the triple is valid iff v & z == 0, i.e. z is
// a "submask" of the complement of v. Rather than checking directly,
// count via: for each pair-AND value v (with its frequency), for each k
// in nums, add freq[v] to the answer if (v & k) == 0.
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int maxVal = 1 << 16;
        vector<int> pairAndCount(maxVal, 0);
        for (int a : nums)
            for (int b : nums)
                pairAndCount[a & b]++;

        long long ans = 0;
        for (int v = 0; v < maxVal; v++) {
            if (pairAndCount[v] == 0) continue;
            for (int k : nums) {
                if ((v & k) == 0) ans += pairAndCount[v];
            }
        }
        return (int)ans;
    }
};
