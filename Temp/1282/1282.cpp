// Link: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> buckets;
        vector<vector<int>> res;
        for (int i = 0; i < (int)groupSizes.size(); i++) {
            int sz = groupSizes[i];
            buckets[sz].push_back(i);
            if ((int)buckets[sz].size() == sz) {
                res.push_back(buckets[sz]);
                buckets[sz].clear();
            }
        }
        return res;
    }
};
