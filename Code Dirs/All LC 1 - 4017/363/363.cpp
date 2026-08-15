// Link: https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(min(m,n)^2 * max(m,n) * log(max(m,n)))  SC: O(max(m,n))
// Approach: fix left/right column pair, compress rows into a 1D sum array,
// then for each prefix sum find the smallest earlier prefix >= (prefix - k)
// using an ordered set (maximizes sum <= k)
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int best = INT_MIN;

        for (int left = 0; left < n; left++) {
            vector<int> rowSum(m, 0);
            for (int right = left; right < n; right++) {
                for (int i = 0; i < m; i++) rowSum[i] += matrix[i][right];

                set<int> prefixes{0};
                int prefix = 0;
                for (int i = 0; i < m; i++) {
                    prefix += rowSum[i];
                    auto it = prefixes.lower_bound(prefix - k);
                    if (it != prefixes.end()) best = max(best, prefix - *it);
                    prefixes.insert(prefix);
                }
            }
        }
        return best;
    }
};
