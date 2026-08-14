// Link: https://leetcode.com/problems/high-access-employees/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> byName;
        for (auto& e : access_times) {
            string name = e[0];
            string t = e[1];
            int hh = stoi(t.substr(0, 2));
            int mm = stoi(t.substr(2, 2));
            byName[name].push_back(hh * 60 + mm);
        }
        vector<string> res;
        for (auto& [name, times] : byName) {
            sort(times.begin(), times.end());
            for (int i = 0; i + 2 < (int)times.size(); i++) {
                if (times[i + 2] - times[i] < 60) {
                    res.push_back(name);
                    break;
                }
            }
        }
        return res;
    }
};
