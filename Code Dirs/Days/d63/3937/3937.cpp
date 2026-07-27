// Link: https://leetcode.com/problems/minimum-operations-to-make-array-modulo-alternating-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*k + k^2) SC: O(k)
// Approach: for each candidate remainder r, the cost to bring nums[i] to
// that remainder mod k is the circular distance min(d, k-d) between
// nums[i]%k and r. Sum these costs separately over even and odd
// indices for every r, then try all distinct (x,y) pairs to find the
// minimum combined cost.
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> costEven(k, 0), costOdd(k, 0);
        for (int i = 0; i < n; i++) {
            int rem = nums[i] % k;
            for (int r = 0; r < k; r++) {
                int d = abs(rem - r);
                int cost = min(d, k - d);
                if (i % 2 == 0) costEven[r] += cost;
                else costOdd[r] += cost;
            }
        }

        long long best = LLONG_MAX;
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                if (x == y) continue;
                best = min(best, costEven[x] + costOdd[y]);
            }
        }
        return (int)best;
    }
};
