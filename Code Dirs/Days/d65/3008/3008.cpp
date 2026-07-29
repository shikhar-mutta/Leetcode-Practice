// Link: https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(|s| + |a| + |b| + occurrences*log), SC: O(|s|)
// Approach: KMP to find all occurrence start indices of a and b in s. For each occurrence of a,
// binary search occurrences of b for any within [i-k, i+k].
class Solution {
public:
    vector<int> kmpFind(const string& text, const string& pat) {
        int n = text.size(), m = pat.size();
        vector<int> fail(m, 0);
        for (int i = 1; i < m; i++) {
            int j = fail[i-1];
            while (j > 0 && pat[i] != pat[j]) j = fail[j-1];
            if (pat[i] == pat[j]) j++;
            fail[i] = j;
        }
        vector<int> occ;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j > 0 && text[i] != pat[j]) j = fail[j-1];
            if (text[i] == pat[j]) j++;
            if (j == m) { occ.push_back(i - m + 1); j = fail[j-1]; }
        }
        return occ;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> occA = kmpFind(s, a);
        vector<int> occB = kmpFind(s, b);

        vector<int> ans;
        for (int i : occA) {
            auto lo = lower_bound(occB.begin(), occB.end(), i - k);
            if (lo != occB.end() && *lo <= i + k) ans.push_back(i);
        }
        return ans;
    }
};
