// Link: https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // approach 1: using unordered_map
    // int numEquivDominoPairs(vector<vector<int>> &dominoes)
    // {
    //     int count = 0;
    //     unordered_map<string, int> mp;

    //     for (auto &d : dominoes)
    //     {
    //         int a = min(d[0], d[1]);
    //         int b = max(d[0], d[1]);
    //         string key = to_string(a) + "," + to_string(b);

    //         count += mp[key];
    //         mp[key]++;
    //     }

    //     return count;
    // }

    // approach 2: using array as hash map
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        int count = 0;
        int mp[100] = {}; // IMP: 100 because max value in domino is 9, so key can be at max 99

        for (auto &d : dominoes)
        {
            int key = min(d[0], d[1]) * 10 + max(d[0], d[1]);
            count += mp[key];
            mp[key]++;
        }

        return count;
    }
};
