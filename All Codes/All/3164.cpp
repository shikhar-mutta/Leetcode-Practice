// Link: https://leetcode.com/problems/find-the-number-of-good-pairs-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(maxVal * log(maxVal) / avg(nums2*k) + n), SC: O(maxVal)
// Approach: For each nums2[i]*k value, mark every multiple up to max(nums1)
// in a "multiple count" array via a sieve-style pass (special-cased when
// the value is 1, since marking every multiple up to maxVal would be too
// slow — instead just tally how many such i's there are and add that count
// directly to every nums1 element). Then for each nums1[j], the number of
// valid nums2 partners is fact[nums1[j]] (multiples-count) plus the "o"
// (divisor-of-everything) count.
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<long long> n2(m, 0);
        for (int i = 0; i < m; i++) {
            n2[i] = 1LL * nums2[i] * k;
        }
        int mx = *max_element(nums1.begin(), nums1.end());
        vector<long long> fact(mx + 2, 0);
        int o = 0;
        for (int i = 0; i < m; i++) {
            if (n2[i] == 1) {
                o++;
                continue;
            }
            for (long long j = n2[i]; j <= mx; j += n2[i]) {
                fact[j]++;
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (fact[nums1[i]] + o);
        }
        return ans;
    }
};
