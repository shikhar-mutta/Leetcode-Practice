// Link: https://leetcode.com/problems/height-checker/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted = heights;
        sort(sorted.begin(), sorted.end());
        int count = 0;
        for (int i = 0; i < (int)heights.size(); i++)
            if (heights[i] != sorted[i]) count++;
        return count;
    }
};
