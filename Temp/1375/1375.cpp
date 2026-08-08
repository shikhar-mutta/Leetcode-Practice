// Link: https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int maxSoFar = 0, count = 0;
        for (int i = 0; i < (int)flips.size(); i++) {
            maxSoFar = max(maxSoFar, flips[i]);
            if (maxSoFar == i + 1) count++;
        }
        return count;
    }
};
