// Link: https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int posLen = 0, negLen = 0, best = 0;
        for (int x : nums) {
            if (x == 0) { posLen = 0; negLen = 0; }
            else if (x > 0) {
                posLen++;
                negLen = (negLen > 0) ? negLen + 1 : 0;
            } else {
                int newPos = (negLen > 0) ? negLen + 1 : 0;
                int newNeg = posLen + 1;
                posLen = newPos;
                negLen = newNeg;
            }
            best = max(best, posLen);
        }
        return best;
    }
};
