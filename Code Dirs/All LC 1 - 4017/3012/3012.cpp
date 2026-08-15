// Link: https://leetcode.com/problems/minimize-length-of-array-using-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int minVal = *min_element(nums.begin(), nums.end());
        int cntMin = 0;
        bool allDivisible = true;
        for (int x : nums) {
            if (x % minVal != 0) allDivisible = false;
            if (x == minVal) cntMin++;
        }
        if (!allDivisible) return 1;
        return (cntMin + 1) / 2;
    }
};
