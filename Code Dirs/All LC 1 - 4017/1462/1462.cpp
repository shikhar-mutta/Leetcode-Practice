// Link: https://leetcode.com/problems/course-schedule-iv/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> reach(numCourses, vector<bool>(numCourses, false));
        for (auto& p : prerequisites) reach[p[0]][p[1]] = true;

        for (int k = 0; k < numCourses; k++)
            for (int i = 0; i < numCourses; i++)
                if (reach[i][k])
                    for (int j = 0; j < numCourses; j++)
                        if (reach[k][j]) reach[i][j] = true;

        vector<bool> res;
        for (auto& q : queries) res.push_back(reach[q[0]][q[1]]);
        return res;
    }
};
