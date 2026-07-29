// Link: https://leetcode.com/problems/find-maximum-number-of-non-intersecting-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubstrings(string word) {
        vector<int> firstOcc(26, -1);
        int count = 0;
        for (int i = 0; i < (int)word.size(); i++) {
            int c = word[i] - 'a';
            if (firstOcc[c] == -1) {
                firstOcc[c] = i;
            } else if (i - firstOcc[c] + 1 >= 4) {
                count++;
                fill(firstOcc.begin(), firstOcc.end(), -1);
            }
        }
        return count;
    }
};
