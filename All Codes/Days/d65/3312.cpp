// Link: https://leetcode.com/problems/sorted-gcd-pair-queries/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(maxVal log maxVal + Q log maxVal), SC: O(maxVal)
// Approach: count pairs by gcd via the classic divisor sieve + inclusion-exclusion. For each g,
// cntMultiple[g] = count of nums that are multiples of g, giving C(cntMultiple[g],2) pairs whose
// gcd is a multiple of g. Subtracting off (processing g descending) the exact-pair counts of all
// larger multiples of g isolates exactPairs[g] = pairs whose gcd is EXACTLY g. Prefix-sum those
// by g ascending, then answer each query (0-indexed rank) via binary search on that prefix sum.
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<long long> freq(maxVal+1, 0);
        for (int x : nums) freq[x]++;

        vector<long long> cntMultiple(maxVal+1, 0);
        for (int g = 1; g <= maxVal; g++)
            for (int m = g; m <= maxVal; m += g)
                cntMultiple[g] += freq[m];

        vector<long long> exactPairs(maxVal+1, 0);
        for (int g = maxVal; g >= 1; g--) {
            long long c = cntMultiple[g];
            exactPairs[g] = c * (c-1) / 2;
            for (int m = 2*g; m <= maxVal; m += g) exactPairs[g] -= exactPairs[m];
        }

        vector<long long> prefix(maxVal+1, 0);
        for (int g = 1; g <= maxVal; g++) prefix[g] = prefix[g-1] + exactPairs[g];

        vector<int> ans;
        for (long long k : queries) {
            // find smallest g with prefix[g] > k
            int lo = 1, hi = maxVal, res = maxVal;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (prefix[mid] > k) { res = mid; hi = mid - 1; }
                else lo = mid + 1;
            }
            ans.push_back(res);
        }
        return ans;
    }
};
