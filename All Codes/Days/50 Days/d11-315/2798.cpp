// Link: https://leetcode.com/problems/number-of-employees-who-met-the-target/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int numberOfEmployeesWhoMetTarget(vector<int> &hours, int target)
    {
        int cnt = 0;
        for (int h : hours)
            if (h >= target)
                cnt++;
        return cnt;
    }
};
