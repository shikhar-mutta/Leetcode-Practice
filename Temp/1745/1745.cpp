// Link: https://leetcode.com/problems/palindrome-partitioning-iv/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) isPal[i][i] = true;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len == 2 || isPal[i+1][j-1])) isPal[i][j] = true;
            }
        }
        for (int i = 1; i < n - 1; i++) {
            for (int j = i; j < n - 1; j++) {
                if (isPal[0][i-1] && isPal[i][j] && isPal[j+1][n-1]) return true;
            }
        }
        return false;
    }
};
