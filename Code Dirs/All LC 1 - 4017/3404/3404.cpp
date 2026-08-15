// Link: https://leetcode.com/problems/count-special-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        unordered_map<long long, int> leftRatios;
        for (int r = 4; r < n; r++) {
            int q = r - 2;
            for (int p = 0; p <= q - 2; p++) {
                int g = gcd(nums[p], nums[q]);
                long long key = (long long)(nums[p] / g) * 2001 + (nums[q] / g);
                leftRatios[key]++;
            }
            for (int s = r + 2; s < n; s++) {
                int g = gcd(nums[s], nums[r]);
                long long key = (long long)(nums[s] / g) * 2001 + (nums[r] / g);
                auto it = leftRatios.find(key);
                if (it != leftRatios.end()) ans += it->second;
            }
        }
        return ans;
    }
};
