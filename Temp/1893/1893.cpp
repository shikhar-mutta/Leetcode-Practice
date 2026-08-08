// Link: https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<bool> covered(52, false);
        for (auto& r : ranges) {
            for (int i = r[0]; i <= r[1]; i++) covered[i] = true;
        }
        for (int i = left; i <= right; i++) {
            if (!covered[i]) return false;
        }
        return true;
    }
};
