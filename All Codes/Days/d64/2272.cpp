// Link: https://leetcode.com/problems/substring-with-largest-variance/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(26^2 * n)  SC: O(1)
// Approach: for every ordered pair (major, minor) of distinct chars, run a
// Kadane-like scan treating major as +1, minor as -1, others ignored;
// track running sum but reset if it goes below 0 UNLESS a minor char has
// been seen (need at least one minor char in the substring for validity).
// Track max sum with at least one minor seen.
class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        for (char maj = 'a'; maj <= 'z'; maj++) {
            for (char min = 'a'; min <= 'z'; min++) {
                if (maj == min) continue;
                if (s.find(maj) == string::npos || s.find(min) == string::npos) continue;
                int cur = 0;
                bool hasMinor = false;
                for (char c : s) {
                    if (c == maj) cur++;
                    else if (c == min) { cur--; hasMinor = true; }
                    else continue;
                    if (hasMinor) ans = max(ans, cur);
                    if (cur < 0) { cur = 0; hasMinor = false; }
                }
            }
        }
        return ans;
    }
};
