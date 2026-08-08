// Link: https://leetcode.com/problems/string-compression-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string s;
    int n;
    vector<vector<int>> memo;

    int calcLen(int count) {
        if (count == 1) return 1;
        if (count < 10) return 2;
        if (count < 100) return 3;
        return 4;
    }

    int dfs(int i, int k) {
        if (k < 0) return INT_MAX / 2;
        if (i >= n) return 0;
        if (memo[i][k] != -1) return memo[i][k];

        int best = dfs(i + 1, k - 1); // delete char i
        int count = 0, del = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == s[i]) count++;
            else {
                del++;
                if (del > k) break;
            }
            best = min(best, calcLen(count) + dfs(j + 1, k - del));
        }
        memo[i][k] = best;
        return best;
    }

    int getLengthOfOptimalCompression(string s, int k) {
        this->s = s;
        n = s.size();
        memo.assign(n, vector<int>(k + 1, -1));
        return dfs(0, k);
    }
};
