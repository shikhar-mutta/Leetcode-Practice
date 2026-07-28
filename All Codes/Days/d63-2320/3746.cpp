// Link: https://leetcode.com/problems/minimum-string-length-after-balanced-removals/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: any two adjacent differing characters can always be paired
// off and removed via some sequence of balanced-substring deletions, so
// the string reduces to only the majority character; the answer is the
// absolute difference between the 'a' and 'b' counts.
class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a = 0, b = 0;
        for (char c : s) (c == 'a' ? a : b)++;
        return abs(a - b);
    }
};
