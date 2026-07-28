// Link: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach: A valid subsequence needs every adjacent pair's sum to share
// the same parity. Two cases: all-same-parity (take every even or every
// odd element), or strictly alternating parity starting from 0 or 1. Try
// all three and return the longest.
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int evenCount = 0, oddCount = 0;
        for (int x : nums) {
            if (x % 2 == 0) evenCount++;
            else oddCount++;
        }
        int best = max(evenCount, oddCount);

        // try alternating parity subsequence
        for (int start = 0; start < 2; start++) {
            int expected = start;
            int len = 0;
            for (int x : nums) {
                int p = x % 2;
                if (p == expected) {
                    len++;
                    expected = 1 - expected;
                }
            }
            best = max(best, len);
        }

        return best;
    }
};
