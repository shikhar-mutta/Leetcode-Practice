// Link: https://leetcode.com/problems/maximum-substrings-with-distinct-start/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: partition s into contiguous parts with pairwise distinct
// start characters, maximizing part count. Splitting exactly at each
// character's first occurrence (positions are already increasing) always
// gives a valid partition with one part per distinct character, and no
// partition can exceed the number of distinct characters (each part
// needs a unique start). So the answer is simply the count of distinct
// characters in s.
class Solution {
public:
    int maxDistinct(string s) {
        return unordered_set<char>(s.begin(), s.end()).size();
    }
};
