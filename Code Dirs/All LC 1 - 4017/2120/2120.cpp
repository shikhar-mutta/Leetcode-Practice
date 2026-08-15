// Link: https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.size();
        vector<int> res(m, 0);
        for (int start = 0; start < m; start++) {
            int r = startPos[0], c = startPos[1];
            int count = 0;
            for (int i = start; i < m; i++) {
                int nr = r, nc = c;
                if (s[i] == 'U') nr--;
                else if (s[i] == 'D') nr++;
                else if (s[i] == 'L') nc--;
                else nc++;
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) break;
                r = nr; c = nc;
                count++;
            }
            res[start] = count;
        }
        return res;
    }
};
