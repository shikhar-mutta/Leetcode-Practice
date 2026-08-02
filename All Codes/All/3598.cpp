// Link: https://leetcode.com/problems/longest-common-prefix-between-adjacent-strings-after-removals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lcpLen(const string& a, const string& b) {
        int n = min(a.size(), b.size());
        int i = 0;
        while (i < n && a[i] == b[i]) i++;
        return i;
    }

    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        vector<int> lcpArr(n > 1 ? n - 1 : 0);
        for (int j = 0; j + 1 < n; j++) lcpArr[j] = lcpLen(words[j], words[j+1]);

        int m = lcpArr.size();
        vector<int> prefMax(m), sufMax(m);
        if (m > 0) {
            prefMax[0] = lcpArr[0];
            for (int j = 1; j < m; j++) prefMax[j] = max(prefMax[j-1], lcpArr[j]);
            sufMax[m-1] = lcpArr[m-1];
            for (int j = m - 2; j >= 0; j--) sufMax[j] = max(sufMax[j+1], lcpArr[j]);
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            int maxExcl = 0;
            if (i - 2 >= 0) maxExcl = max(maxExcl, prefMax[i-2]);
            if (i + 1 <= m - 1) maxExcl = max(maxExcl, sufMax[i+1]);
            int newPair = 0;
            if (i - 1 >= 0 && i + 1 < n) newPair = lcpLen(words[i-1], words[i+1]);
            ans[i] = max(maxExcl, newPair);
        }

        return ans;
    }
};
