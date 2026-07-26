// Link: https://leetcode.com/problems/prime-subtraction-operation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log log LIMIT + n * LIMIT) for the sieve + per-element prime scan
// SC: O(LIMIT) for the sieve
// Approach: greedily process left to right, subtracting the LARGEST prime that
// still keeps nums[i] strictly greater than the (already finalized) nums[i-1] —
// minimizing each value maximizes room for later elements. dec is the largest
// legal subtraction (nums[i]-nums[i-1]-1, or nums[i]-1 for i=0 since values must
// stay positive); scan primes downward from dec and stop at the first hit.
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        bool primes[1000] = {0};

        for (int i = 2; i * i < 1000; i++) {
            if (!primes[i]) {
                for (int j = i * i; j < 1000; j += i) {
                    primes[j] = 1;
                }
            }
        }
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int dec;
            if (i != 0)
                dec = nums[i] - nums[i - 1] - 1;
            else
                dec = nums[i] - 1;
            for (int j = dec; j >= 2; j--) {
                if (!primes[j]) {
                    nums[i] -= j;
                    break;
                }
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] >= nums[i + 1])
                return false;
        }
        return true;
    }
};
