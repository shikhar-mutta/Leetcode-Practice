// Link: https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int count = 0;
        for (int i = 0; i < (int)startTime.size(); i++) {
            if (startTime[i] <= queryTime && queryTime <= endTime[i]) count++;
        }
        return count;
    }
};
