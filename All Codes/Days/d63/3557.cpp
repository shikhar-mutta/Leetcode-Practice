// Link: https://leetcode.com/problems/find-maximum-number-of-non-intersecting-substrings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: greedy interval scheduling. Track the first unused occurrence
// of each letter; when the same letter repeats with a gap >= 4 (min
// substring length), greedily close a substring there (closing as early
// as possible maximizes future opportunities) and reset all tracked
// first-occurrences since nothing can overlap it.
class Solution {
public:
    int maxSubstrings(string word) {
        vector<int> first(26, -1);
        int count = 0;
        for (int i = 0; i < (int)word.size(); i++) {
            int c = word[i] - 'a';
            if (first[c] == -1) {
                first[c] = i;
            } else if (i - first[c] + 1 >= 4) {
                count++;
                fill(first.begin(), first.end(), -1);
            }
        }
        return count;
    }
};
