// Link: https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(maxXOR)
// Approach: a subarray is "beautiful" (reducible to all zeros) iff its XOR is 0,
// so count pairs of equal prefix-XOR values. First pass finds the max running
// prefix XOR to size a frequency array; second pass counts, for each prefix XOR,
// how many earlier prefixes shared that same value (fq[0]=1 seeds the empty prefix).
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int maxXOR = 0;
        int exor = 0;
        for (int i = 0; i < nums.size(); i++)
            exor ^= nums[i], maxXOR = max(maxXOR, exor);

        vector<int> fq(maxXOR + 1, 0);
        exor = 0;
        long long count = 0LL;
        fq[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            exor ^= nums[i];
            count += fq[exor];
            fq[exor]++;
        }

        return count;
    }
};
