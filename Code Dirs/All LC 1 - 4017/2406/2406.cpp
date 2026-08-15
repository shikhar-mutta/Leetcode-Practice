// Link: https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> ends;
        for (auto &iv : intervals) {
            if (!ends.empty() && ends.top() < iv[0]) ends.pop();
            ends.push(iv[1]);
        }
        return ends.size();
    }
};
