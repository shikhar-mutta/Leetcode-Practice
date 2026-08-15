// Link: https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        int d = __gcd(n, k);
        for (int r = 0; r < m; r++) {
            for (int j = 0; j < n; j++) {
                if (mat[r][j] != mat[r][j % d]) return false;
            }
        }
        return true;
    }
};
