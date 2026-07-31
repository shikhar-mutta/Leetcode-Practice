// Link: https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
//  Approach: patience-sorting LIS variant for non-decreasing subsequences.
//  Maintain tails[] of the smallest tail value for each subsequence length;
//  for each obstacle, upper_bound finds where it replaces (allows equal
//  values to extend), giving that position's answer as index+1.
class Solution
{
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    {
        vector<int> lis(obstacles.size(), 1);
        vector<int> temp;
        for (int i = 0; i < obstacles.size(); i++)
        {
            if (temp.size() == 0 || obstacles[i] >= temp.back())
            {
                temp.push_back(obstacles[i]);
                lis[i] = temp.size();
            }
            else
            {
                auto it = upper_bound(temp.begin(), temp.end(), obstacles[i]);
                int ind = it - temp.begin();
                temp[ind] = obstacles[i];
                lis[i] = ind + 1;
            }
        }
        return lis;
    }
};