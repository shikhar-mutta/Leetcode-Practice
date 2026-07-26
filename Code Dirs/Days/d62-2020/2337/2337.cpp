// Link: https://leetcode.com/problems/move-pieces-to-obtain-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: two pointers skipping over '_' characters in start and target
// simultaneously, comparing only the non-blank "piece" characters. The
// pieces (L's and R's, ignoring blanks) must appear in the same order in
// both strings, and each individual piece can only move left (L) or right
// (R) - so an L must never need to move rightward (its target index must
// be <= its current index) and an R must never need to move leftward.
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;

        while (i < n || j < n) {
            while (i < n && start[i] == '_')
                ++i;
            while (j < n && target[j] == '_')
                ++j;

            if (i == n || j == n)
                return i == n && j == n; // both must finish together

            if (start[i] != target[j])
                return false; // piece order mismatch

            if (start[i] == 'L' && i < j)
                return false; // L can't move right
            if (start[i] == 'R' && i > j)
                return false; // R can't move left

            ++i;
            ++j;
        }
        return true;
    }
};
