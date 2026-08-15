// Link: https://leetcode.com/problems/finding-the-users-active-minutes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> userMinutes;
        for (auto& l : logs) userMinutes[l[0]].insert(l[1]);

        vector<int> res(k, 0);
        for (auto& [user, minutes] : userMinutes) {
            int uam = minutes.size();
            if (uam >= 1 && uam <= k) res[uam - 1]++;
        }
        return res;
    }
};
