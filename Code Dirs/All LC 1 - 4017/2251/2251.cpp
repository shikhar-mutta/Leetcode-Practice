// Link: https://leetcode.com/problems/number-of-flowers-in-full-bloom/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> starts, ends;
        for (auto& f : flowers) { starts.push_back(f[0]); ends.push_back(f[1]); }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        vector<int> res(people.size());
        for (int i = 0; i < (int)people.size(); i++) {
            int t = people[i];
            int startedCount = upper_bound(starts.begin(), starts.end(), t) - starts.begin();
            int endedCount = lower_bound(ends.begin(), ends.end(), t) - ends.begin();
            res[i] = startedCount - endedCount;
        }
        return res;
    }
};
