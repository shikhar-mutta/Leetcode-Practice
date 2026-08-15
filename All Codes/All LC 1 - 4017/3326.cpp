// Link: https://leetcode.com/problems/minimum-division-operations-to-make-array-non-decreasing/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(maxVal log log maxVal) precompute, O(n) per call, SC: O(maxVal)
// Approach: Precompute smallest-prime-factor (spf) for every value up to
// 1e6 via a sieve. Scan nums right to left; whenever nums[i] > nums[i+1],
// it must be divided down to its smallest prime factor (the largest
// possible single reduction), costing one operation. If it's still too big
// afterward, no further operation can help (dividing a prime does nothing),
// so return -1.
class Solution {
private:
    static vector<int> buildSPF() {
        const int MAX = 1000000;
        vector<int> spf(MAX + 1);

        for (int i = 0; i <= MAX; ++i)
            spf[i] = i;

        spf[0] = 0;
        spf[1] = 1;

        for (int i = 2; i * i <= MAX; ++i) {
            if (spf[i] != i)
                continue;

            for (int j = i * i; j <= MAX; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }

        return spf;
    }

    static const vector<int> spf;

public:
    int minOperations(vector<int>& nums) {
        int operations = 0;

        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] <= nums[i + 1])
                continue;

            nums[i] = spf[nums[i]];
            ++operations;

            if (nums[i] > nums[i + 1])
                return -1;
        }

        return operations;
    }
};

const vector<int> Solution::spf = Solution::buildSPF();
