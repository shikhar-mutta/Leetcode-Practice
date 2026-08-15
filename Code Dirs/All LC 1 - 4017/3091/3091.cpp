// Link: https://leetcode.com/problems/apply-operations-to-make-sum-of-array-greater-than-or-equal-to-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(int k) {
        int best = INT_MAX;
        for (int a = 0; a < k; a++) {
            long long val = 1 + a;
            long long copies = (k + val - 1) / val;
            long long d = copies - 1;
            best = min((long long)best, a + d);
        }
        return best;
    }
};
