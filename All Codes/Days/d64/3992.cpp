// Link: https://leetcode.com/problems/rearrange-string-to-avoid-character-pair/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: place all y's first, then all other characters (excluding
// x and y) in any order, then all x's last — guarantees every y precedes
// every x while satisfying the permutation requirement.
class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string ys, others, xs;
        for (char c : s) {
            if (c == y) ys += c;
            else if (c == x) xs += c;
            else others += c;
        }
        return ys + others + xs;
    }
};
