// Link: https://leetcode.com/problems/find-the-smallest-balanced-index/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: prefix sums give the left sum at each index; a capped
// suffix product (saturating once it exceeds the max possible left sum,
// avoiding overflow) gives the right product. Scan left to right for
// the first index where they match.
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        const long long CAP = 200000000000000LL; // > max possible left sum (1e5 * 1e9)

        vector<long long> leftSum(n + 1, 0);
        for (int i = 0; i < n; i++) leftSum[i+1] = leftSum[i] + nums[i];

        vector<long long> rightProd(n + 1);
        rightProd[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (rightProd[i+1] > CAP) rightProd[i] = rightProd[i+1];
            else {
                long long p = rightProd[i+1] * nums[i];
                rightProd[i] = (p > CAP) ? CAP + 1 : p;
            }
        }

        for (int i = 0; i < n; i++) {
            if (leftSum[i] == rightProd[i+1]) return i;
        }
        return -1;
    }
};
