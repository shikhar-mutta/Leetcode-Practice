// Link: https://leetcode.com/problems/distribute-money-to-maximum-children/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)
// SC: O(1)
// Approach: give every child $1 first (must, else infeasible), then greedily
// convert as many children as possible into $8-children (7 more each) capped by
// leftover money and child count. Two edge cases break an exact-8 assignment:
// leftover money with no children left to absorb it, or exactly one child left
// with $4 total (must avoid landing exactly on $4) — in both cases give up one
// $8-child so the remainder is a strictly-less-than-8 amount distributed elsewhere.
class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) return -1;   // can't give everyone at least 1

        money -= children;                  // give each child 1 dollar first
        // now distribute remaining, each 8-dollar child needs 7 more
        int eights = min(money / 7, children);
        money -= eights * 7;
        int remaining = children - eights;

        // if no children left but money remains, give extra to one 8-child (no longer exactly 8)
        if (remaining == 0 && money > 0) --eights;
        // if exactly one child left with exactly 3 dollars extra (total 4), avoid it
        else if (remaining == 1 && money == 3) --eights;

        return eights;
    }
};
