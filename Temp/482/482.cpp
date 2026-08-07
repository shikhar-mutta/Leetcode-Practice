// Link: https://leetcode.com/problems/license-key-formatting/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: strip dashes and uppercase, then build result from the end in
// groups of k, inserting a dash between groups
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string clean;
        for (char c : s) if (c != '-') clean += toupper(c);

        string res;
        int count = 0;
        for (int i = clean.size() - 1; i >= 0; i--) {
            if (count == k) { res += '-'; count = 0; }
            res += clean[i];
            count++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
