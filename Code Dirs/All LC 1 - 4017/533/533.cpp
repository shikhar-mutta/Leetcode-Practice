// Link: https://leetcode.com/problems/lonely-pixel-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(m*n)
// Approach: group identical rows by their pattern string; for each row
// pattern occurring exactly target times, verify each black column in that
// pattern also has exactly target black pixels total
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int target) {
        int m = picture.size(), n = picture[0].size();
        vector<int> colCount(n, 0);
        vector<string> rows(m);
        for (int i = 0; i < m; i++) {
            string r(picture[i].begin(), picture[i].end());
            rows[i] = r;
            for (int j = 0; j < n; j++) if (picture[i][j] == 'B') colCount[j]++;
        }

        unordered_map<string, int> rowFreq;
        for (auto& r : rows) rowFreq[r]++;

        int total = 0;
        for (auto& [pattern, freq] : rowFreq) {
            if (freq != target) continue;
            for (int j = 0; j < n; j++) {
                if (pattern[j] == 'B' && colCount[j] == target) total += freq;
            }
        }
        return total;
    }
};
