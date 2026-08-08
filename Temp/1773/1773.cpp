// Link: https://leetcode.com/problems/count-items-matching-a-rule/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int idx = (ruleKey == "type") ? 0 : (ruleKey == "color") ? 1 : 2;
        int count = 0;
        for (auto& item : items) {
            if (item[idx] == ruleValue) count++;
        }
        return count;
    }
};
