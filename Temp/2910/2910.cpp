// Link: https://leetcode.com/problems/minimum-number-of-groups-to-create-a-valid-assignment/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& balls) {
        unordered_map<int, int> freq;
        for (int b : balls) freq[b]++;
        int maxFreq = 0;
        for (auto& [v, c] : freq) maxFreq = max(maxFreq, c);

        for (int k = maxFreq; k >= 1; k--) {
            long long total = 0;
            bool ok = true;
            for (auto& [v, c] : freq) {
                long long groups = (c + k - 1) / k;
                if (c < groups * (k - 1)) { ok = false; break; }
                total += groups;
            }
            if (ok) return (int)total;
        }
        return -1;
    }
};
