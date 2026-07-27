// Link: https://leetcode.com/problems/resulting-string-after-adjacent-removals/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: stack simulation. Two letters are removable if they're
// adjacent in the alphabet cyclically (difference of 1 or 25, covering
// the z-a wraparound). Push each char; if it's adjacent to the current
// stack top, pop instead of pushing.
class Solution {
public:
    string resultingString(string s) {
        string stk;
        for (char c : s) {
            if (!stk.empty()) {
                int d = abs(stk.back() - c);
                if (d == 1 || d == 25) { stk.pop_back(); continue; }
            }
            stk.push_back(c);
        }
        return stk;
    }
};
