// Link: https://leetcode.com/problems/odd-string-difference/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words.size();
        int m = words[0].size();
        vector<vector<int>> diffs(n, vector<int>(m - 1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j + 1 < m; j++)
                diffs[i][j] = words[i][j+1] - words[i][j];

        map<vector<int>, vector<int>> groups;
        for (int i = 0; i < n; i++) groups[diffs[i]].push_back(i);

        for (auto &[key, idxs] : groups)
            if (idxs.size() == 1) return words[idxs[0]];
        return "";
    }
};
