// Link: https://leetcode.com/problems/minimum-adjacent-swaps-to-alternate-parity/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: collect the positions of all odd elements (in order). For an
// alternating target where odd numbers sit at indices of a fixed parity
// `base` (0 or 1), the target slots are base, base+2, base+4, ...; since
// relative order among same-parity elements never needs to change for an
// optimal adjacent-swap solution, the minimum swap count for that target
// is the sum of |actualPos - targetSlot| matching odd elements in order.
// Try both base values (whichever matches the actual odd count) and take
// the minimum feasible cost, or -1 if neither slot count matches.
class Solution {
    long long cost(vector<int>& oddPos, int base) {
        long long total = 0;
        for (int k = 0; k < (int)oddPos.size(); k++) total += abs(oddPos[k] - (base + 2 * k));
        return total;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> oddPos;
        for (int i = 0; i < n; i++) if (nums[i] % 2 != 0) oddPos.push_back(i);
        int countOdd = oddPos.size();

        long long best = LLONG_MAX;
        for (int base = 0; base <= 1; base++) {
            int reqCount = (n - base + 1) / 2; // count of indices in [0,n-1] with i%2==base
            if (countOdd == reqCount) best = min(best, cost(oddPos, base));
        }
        return best == LLONG_MAX ? -1 : (int)best;
    }
};
