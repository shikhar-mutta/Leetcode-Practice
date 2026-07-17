// Link: https://leetcode.com/problems/high-access-employees/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) where n is the number of access times
    // SC: O(n) where n is the number of access times
    // Approach:
    // 1. Create a map to store the access times of each employee.
    // 2. For each employee, sort their access times and check if there are 3 access times within 1 hour.
    // 3. If there are, add the employee to the result vector.
    int getMinutes(string &s)
    {
        int hour = (s[0] - '0') * 10 + (s[1] - '0');
        int minute = (s[2] - '0') * 10 + (s[3] - '0');
        return hour * 60 + minute;
    }
    vector<string> findHighAccessEmployees(vector<vector<string>> &access_times)
    {
        int n = access_times.size();
        unordered_map<string, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[access_times[i][0]].push_back(getMinutes(access_times[i][1]));
        }
        vector<string> ans;
        for (auto &it : mp)
        {
            auto &v = it.second;
            int sz = v.size();
            sort(v.begin(), v.end());
            for (int i = 0; i + 2 < sz; i++)
            {
                if (v[i + 2] - v[i] < 60)
                {
                    ans.push_back(it.first);
                    break;
                }
            }
        }
        // sort(ans.begin(), ans.end());
        return ans;
    }
};