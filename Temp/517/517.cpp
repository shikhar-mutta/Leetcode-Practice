// Link: https://leetcode.com/problems/super-washing-machines/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: target = avg; track running balance (excess/deficit) crossing
// each boundary; answer is max of (single machine's excess over target,
// max absolute running balance seen)
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int total = accumulate(machines.begin(), machines.end(), 0);
        if (total % n != 0) return -1;
        int target = total / n;

        int result = 0, balance = 0;
        for (int m : machines) {
            int diff = m - target;
            balance += diff;
            result = max({result, abs(balance), diff});
        }
        return result;
    }
};
