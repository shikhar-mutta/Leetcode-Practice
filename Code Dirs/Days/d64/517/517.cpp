// Link: https://leetcode.com/problems/super-washing-machines/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(1)
// Approach: if total isn't divisible by n, impossible. Otherwise the
// answer is the max over all machines of max(|prefix load imbalance|,
// single-machine excess), since one move can shift at most 1 dress
// across a boundary but a machine with a large local excess needs that
// many moves regardless of the running balance.
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int total = accumulate(machines.begin(), machines.end(), 0);
        if (total % n != 0) return -1;
        int target = total / n;
        int ans = 0, prefix = 0;
        for (int x : machines) {
            int diff = x - target;
            prefix += diff;
            ans = max({ans, abs(prefix), diff});
        }
        return ans;
    }
};
