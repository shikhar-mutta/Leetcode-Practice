// Link: https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) + O(nlogn) + O(nlogn) ~ O(nlogn)
// SC: O(n)
// Approach:
//  1. Create a map to store the name and the corresponding time in minutes.
//  2. For each name, sort the time in minutes and check if there are three or more times within a one-hour period.
//  3. If found, add the name to the result vector.
//  4. Finally, sort the result vector and return it.

class Solution
{
public:
    int calcTime(string &s1)
    {
        return ((s1[0] - '0') * 10 + s1[1] - '0') * 60 + ((s1[3] - '0') * 10 + s1[4] - '0');
    }

    vector<string> alertNames(vector<string> &keyName, vector<string> &keyTime)
    {
        int n = keyName.size();
        unordered_map<string, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[keyName[i]].push_back(calcTime(keyTime[i]));
        }
        vector<string> res;
        for (auto &[name, vec] : mp)
        {
            sort(vec.begin(), vec.end());
            int sz = vec.size();
            if (sz <= 2)
                continue;
            for (int i = 0; i <= sz - 3; i++)
            {
                if (vec[i + 2] - vec[i] <= 60)
                {
                    res.push_back(name);
                    break;
                }
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};