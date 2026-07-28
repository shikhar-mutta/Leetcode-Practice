// Link: https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(n)
// Approach: patience-sorting LIS variant for non-decreasing subsequences.
// Maintain tails[] of the smallest tail value for each subsequence length;
// for each obstacle, upper_bound finds where it replaces (allows equal
// values to extend), giving that position's answer as index+1.
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> tails;
        vector<int> res;
        for (int x : obstacles) {
            auto it = upper_bound(tails.begin(), tails.end(), x);
            int idx = it - tails.begin();
            if (it == tails.end()) tails.push_back(x);
            else *it = x;
            res.push_back(idx + 1);
        }
        return res;
    }
};
