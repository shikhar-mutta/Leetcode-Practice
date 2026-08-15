// Link: https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> tails;
        vector<int> res;
        for (int x : obstacles) {
            auto it = upper_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) {
                tails.push_back(x);
                res.push_back(tails.size());
            } else {
                *it = x;
                res.push_back(it - tails.begin() + 1);
            }
        }
        return res;
    }
};
