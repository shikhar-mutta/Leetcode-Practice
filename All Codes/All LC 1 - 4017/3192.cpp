// Link: https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach: Each operation flips a suffix starting at some index, so
// scanning left to right, track a running "flip" parity: if the current
// (parity-adjusted) value is 0, an operation must start here — toggle the
// flip state and count it; this greedily fixes every element using the
// fewest suffix flips.
class Solution {
public:
    int minOperations(vector<int>& nums)
    {
        int flip=0;
        int count=0;
        for(int i:nums)
        {
            if(flip==0 && i==0)
            {
                flip=1;
                count++;
            }
            else if(flip==1 && i==1)
            {
                flip=0;
                count++;
            }
        }
        return count;

    }
};
