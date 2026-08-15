// Link: https://leetcode.com/problems/palindrome-partitioning-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n^2)
// Approach: precompute isPal[i][j] via standard expand/DP, then cuts[i] = min cuts for s[0..i),
// trying every palindromic suffix ending at i
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<char>> isPal(n, vector<char>(n, false));
        for (int i = 0; i < n; i++) isPal[i][i] = true;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len == 2 || isPal[i+1][j-1])) isPal[i][j] = true;
            }
        }
        vector<int> cuts(n + 1, 0);
        cuts[0] = -1;
        for (int i = 1; i <= n; i++) {
            cuts[i] = i - 1;
            for (int j = 0; j < i; j++) {
                if (isPal[j][i-1]) cuts[i] = min(cuts[i], cuts[j] + 1);
            }
        }
        return cuts[n];
    }
};
