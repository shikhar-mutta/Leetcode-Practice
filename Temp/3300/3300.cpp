// Link: https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
        int best = INT_MAX;
        for (int x : nums) {
            int s = 0;
            while (x > 0) { s += x % 10; x /= 10; }
            best = min(best, s);
        }
        return best;
    }
};
