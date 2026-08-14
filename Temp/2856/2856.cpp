// Link: https://leetcode.com/problems/minimum-array-length-after-pair-removals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int maxFreq = 0;
        for (int x : nums) maxFreq = max(maxFreq, ++freq[x]);
        if (maxFreq > n - maxFreq) return 2 * maxFreq - n;
        return n % 2;
    }
};
