// Link: https://leetcode.com/problems/delete-columns-to-make-sorted-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), cols = strs[0].size();
        vector<bool> sortedPair(n - 1, false);
        int deletions = 0;
        for (int c = 0; c < cols; c++) {
            bool needDelete = false;
            for (int i = 0; i + 1 < n; i++) {
                if (!sortedPair[i] && strs[i][c] > strs[i+1][c]) {
                    needDelete = true;
                    break;
                }
            }
            if (needDelete) {
                deletions++;
            } else {
                for (int i = 0; i + 1 < n; i++) {
                    if (strs[i][c] < strs[i+1][c]) sortedPair[i] = true;
                }
            }
        }
        return deletions;
    }
};
