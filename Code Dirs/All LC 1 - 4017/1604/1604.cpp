// Link: https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> times;
        for (int i = 0; i < (int)keyName.size(); i++) {
            int h = (keyTime[i][0]-'0')*10 + (keyTime[i][1]-'0');
            int m = (keyTime[i][3]-'0')*10 + (keyTime[i][4]-'0');
            times[keyName[i]].push_back(h * 60 + m);
        }

        vector<string> res;
        for (auto& [name, ts] : times) {
            vector<int> sorted = ts;
            sort(sorted.begin(), sorted.end());
            for (int i = 0; i + 2 < (int)sorted.size(); i++) {
                if (sorted[i+2] - sorted[i] <= 60) {
                    res.push_back(name);
                    break;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
