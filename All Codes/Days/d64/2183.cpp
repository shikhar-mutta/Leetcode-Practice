// Link: https://leetcode.com/problems/count-array-pairs-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n * d(k))  SC: O(d(k))
// Approach: for each divisor d of k, maintain count of nums seen so far
// divisible by d. A new num pairs with all previous nums divisible by
// need = k / gcd(num, k), since num*prev % k == 0 iff prev is a multiple
// of need. Add ans += cnt[need], then update cnt for all divisors of num.
class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        vector<long long> divisors;
        for (long long d = 1; d * d <= k; d++) {
            if (k % d == 0) {
                divisors.push_back(d);
                if (d != k / d) divisors.push_back(k / d);
            }
        }
        unordered_map<long long, long long> cnt;
        long long ans = 0;
        for (int num : nums) {
            long long need = k / gcd((long long)num, (long long)k);
            ans += cnt[need];
            for (long long d : divisors) {
                if (num % d == 0) cnt[d]++;
            }
        }
        return ans;
    }
};
