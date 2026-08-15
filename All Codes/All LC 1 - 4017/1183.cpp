// Link: https://leetcode.com/problems/maximum-number-of-ones/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        vector<int> counts;
        for (int r = 0; r < sideLength; r++) {
            for (int c = 0; c < sideLength; c++) {
                int rowCount = (width - r + sideLength - 1) / sideLength;
                int colCount = (height - c + sideLength - 1) / sideLength;
                counts.push_back(rowCount * colCount);
            }
        }
        sort(counts.rbegin(), counts.rend());
        int total = 0;
        for (int i = 0; i < maxOnes && i < (int)counts.size(); i++) total += counts[i];
        return total;
    }
};
