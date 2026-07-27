// Link: https://leetcode.com/problems/find-the-child-who-has-the-ball-after-k-seconds/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1), SC: O(1)
// Approach: The ball bounces back and forth in a cycle of length
// 2*(n-1) (0 -> n-1 -> 0). Reduce k mod that cycle; if it lands in the
// first half (still heading forward) the position is k itself, otherwise
// it's on the way back, so subtract from the cycle length.
class Solution {
public:
    int numberOfChild(int n, int k) {
        int cycle = 2 * (n - 1);
        k %= cycle;
        if (k < n - 1) {
            return k;
        } else {
            return cycle - k;
        }
    }
};
