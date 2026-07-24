// Link: https://leetcode.com/problems/count-of-matches-in-tournament/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) where n is the input number.
// SC: O(1) for storing the result.
// Approach:
//      1. The number of matches played in a tournament is always n - 1, where n is the number of teams.
//      2. This is because in each match, one team is eliminated, and the tournament continues until only one team remains.
//      3. Therefore, the total number of matches played is equal to the number of teams minus one.
class Solution
{
public:
    int numberOfMatches(int n) { return n - 1; }
};