// Link: https://leetcode.com/problems/valid-word-square/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(1)
// Approach: word square valid iff words[i][j] == words[j][i] for all i,j
// within bounds (out-of-bounds must match too, i.e. neither side has a char)
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (int)words[i].size(); j++) {
                if (j >= n || i >= (int)words[j].size() || words[i][j] != words[j][i]) return false;
            }
        }
        return true;
    }
};
