// Link: https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long total = 0, maxVal = 0;
        for (int x : milestones) {
            total += x;
            maxVal = max(maxVal, (long long)x);
        }
        long long rest = total - maxVal;
        if (maxVal > rest + 1) return 2 * rest + 1;
        return total;
    }
};
