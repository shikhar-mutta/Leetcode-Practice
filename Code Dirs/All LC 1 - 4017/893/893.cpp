// Link: https://leetcode.com/problems/groups-of-special-equivalent-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> groups;
        for (auto& w : words) {
            string even, odd;
            for (int i = 0; i < (int)w.size(); i++) {
                if (i % 2 == 0) even += w[i];
                else odd += w[i];
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            groups.insert(even + "|" + odd);
        }
        return groups.size();
    }
};
