// Link: https://leetcode.com/problems/sorted-gcd-pair-queries/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxVal + 1, 0);
        for (int x : nums) freq[x]++;

        vector<long long> cnt(maxVal + 1, 0); // cnt[g] = number of elements divisible by g
        for (int g = 1; g <= maxVal; g++) {
            for (int m = g; m <= maxVal; m += g) cnt[g] += freq[m];
        }

        vector<long long> exact(maxVal + 1, 0);
        for (int g = maxVal; g >= 1; g--) {
            long long total = cnt[g] * (cnt[g] - 1) / 2;
            for (int m = 2 * g; m <= maxVal; m += g) total -= exact[m];
            exact[g] = total;
        }

        vector<long long> prefix(maxVal + 1, 0);
        for (int g = 1; g <= maxVal; g++) prefix[g] = prefix[g-1] + exact[g];

        vector<int> res;
        res.reserve(queries.size());
        for (long long q : queries) {
            long long target = q + 1; // 1-indexed count
            int lo = 1, hi = maxVal;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (prefix[mid] >= target) hi = mid;
                else lo = mid + 1;
            }
            res.push_back(lo);
        }
        return res;
    }
};
