// Link: https://leetcode.com/problems/count-prime-gap-balanced-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(n)
// Approach: two-pointer over the right endpoint r, keeping a multiset of
// prime values currently in the window [l, r]; shrink l while the window
// has >=2 primes and their gap exceeds k (this l only moves forward
// across the whole scan, a standard monotonic sliding window since
// removing left elements never increases the remaining primes' gap).
// After adjusting, l is the smallest valid left boundary satisfying the
// gap constraint for this r. Separately, having >=2 primes requires
// l <= position of the second-most-recent prime at/before r. The count
// of valid left endpoints for this r is the overlap of both ranges.
class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> sieve(max(2, maxVal + 1), true);
        sieve[0] = false;
        if (sieve.size() > 1) sieve[1] = false;
        for (int i = 2; (long long)i * i < (int)sieve.size(); i++)
            if (sieve[i]) for (int j = i * i; j < (int)sieve.size(); j += i) sieve[j] = false;

        int n = nums.size();
        multiset<int> window;
        vector<int> primePos;
        long long ans = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            if (sieve[nums[r]]) { window.insert(nums[r]); primePos.push_back(r); }

            while (window.size() >= 2 && (*window.rbegin() - *window.begin()) > k) {
                if (sieve[nums[l]]) window.erase(window.find(nums[l]));
                l++;
            }

            if (primePos.size() >= 2) {
                int secondLast = primePos[primePos.size() - 2];
                int upper = min(r, secondLast);
                if (upper >= l) ans += upper - l + 1;
            }
        }
        return (int)ans;
    }
};
