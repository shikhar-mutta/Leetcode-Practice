// Link: https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: each second, every "01" pair simultaneously becomes "10",
// effectively letting each 1 move one step left past an adjacent 0. Scan
// left to right tracking the running count of 0's seen so far; whenever a
// 1 is encountered with zeros before it, its finishing time is bounded by
// both zeroCount (it can move at most one step per second, capped by how
// many 0's it still needs to cross) and result+1 (it can't finish before
// the previous 1 already in motion clears the way) - take the max of
// those two bounds as the new running result.
class Solution {
public:
    int secondsToRemoveOccurrences(string s) {

        int result = 0;
        int zeroCount = 0;
        for(auto c : s) {
            if(c == '0') {
                zeroCount++;
            }
            else if(zeroCount > 0) {
                result = max(result + 1, zeroCount);
            }
        }
        return result;
    }
};
