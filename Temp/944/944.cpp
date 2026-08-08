// Link: https://leetcode.com/problems/delete-columns-to-make-sorted/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        int cols = strs[0].size();
        for (int j = 0; j < cols; j++) {
            for (int i = 1; i < (int)strs.size(); i++) {
                if (strs[i][j] < strs[i-1][j]) { count++; break; }
            }
        }
        return count;
    }
};
