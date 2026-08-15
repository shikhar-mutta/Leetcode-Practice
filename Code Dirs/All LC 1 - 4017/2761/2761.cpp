// Link: https://leetcode.com/problems/prime-pairs-with-target-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> isComposite(n + 1, false);
        for (int i = 2; (long long)i * i <= n; i++) {
            if (!isComposite[i])
                for (long long j = (long long)i * i; j <= n; j += i) isComposite[j] = true;
        }

        vector<vector<int>> ans;
        for (int i = 2; i <= n / 2; i++) {
            int j = n - i;
            if (j < 2 || i > n || j > n) continue;
            if (!isComposite[i] && !isComposite[j]) ans.push_back({i, j});
        }
        return ans;
    }
};
