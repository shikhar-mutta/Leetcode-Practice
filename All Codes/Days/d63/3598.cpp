// Link: https://leetcode.com/problems/longest-common-prefix-between-adjacent-strings-after-removals/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * L) SC: O(n)
// Approach: precompute lcp[i] = LCP length of adjacent words[i],words[i+1].
// Removing word i deletes the pair-edges (i-1,i) and (i,i+1) and, if both
// neighbors exist, creates a new edge between words[i-1] and words[i+1].
// The answer is the max of: the best lcp among all other (unaffected)
// edges (via prefix/suffix max arrays), and that new edge's LCP if it
// exists.
class Solution {
    int lcpLen(const string& a, const string& b) {
        int n = min(a.size(), b.size()), i = 0;
        while (i < n && a[i] == b[i]) i++;
        return i;
    }
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        vector<int> lcp(max(0, n - 1));
        for (int i = 0; i < n - 1; i++) lcp[i] = lcpLen(words[i], words[i+1]);

        int m = lcp.size();
        vector<int> prefixMax(m, 0), suffixMax(m, 0);
        for (int i = 0; i < m; i++) prefixMax[i] = max(i > 0 ? prefixMax[i-1] : 0, lcp[i]);
        for (int i = m - 1; i >= 0; i--) suffixMax[i] = max(i + 1 < m ? suffixMax[i+1] : 0, lcp[i]);

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            int best = 0;
            if (i - 2 >= 0) best = max(best, prefixMax[i-2]);
            if (i + 1 < m) best = max(best, suffixMax[i+1]);
            if (i - 1 >= 0 && i + 1 < n) best = max(best, lcpLen(words[i-1], words[i+1]));
            ans[i] = best;
        }
        return ans;
    }
};
