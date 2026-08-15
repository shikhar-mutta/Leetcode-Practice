// Link: https://leetcode.com/problems/reach-a-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sqrt(target)) SC: O(1)
// Approach: work with abs(target); find smallest n where sum 1..n >= target; if the overshoot is even, done; if odd, increment n by 1 or 2 (whichever makes overshoot even) since flipping a step of parity-matching sign changes sum by an even amount.
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        long long sum = 0;
        int n = 0;
        while (sum < target) {
            n++;
            sum += n;
        }
        while ((sum - target) % 2 != 0) {
            n++;
            sum += n;
        }
        return n;
    }
};
