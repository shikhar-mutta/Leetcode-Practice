// Link: https://leetcode.com/problems/minimum-time-to-break-locks-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n! * n) SC: O(n)
// Approach: n is small, so brute force every permutation of the order in
// which locks are broken. For a fixed order, energy resets to 0 and the
// factor X increases by k after each lock; time for a lock at current X
// is ceil(strength/X). Take the minimum total time over all permutations.
class Solution {
public:
    int findMinimumTime(vector<int>& strength, int k) {
        int n = strength.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        int best = INT_MAX;
        do {
            long long x = 1, total = 0;
            for (int i : idx) {
                total += (strength[i] + x - 1) / x;
                x += k;
            }
            best = min(best, (int)total);
        } while (next_permutation(idx.begin(), idx.end()));
        return best;
    }
};
