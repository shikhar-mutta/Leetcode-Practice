// Link: https://leetcode.com/problems/custom-sort-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + |order|) SC: O(1)
// Approach: count occurrences of each char in s; emit chars in order's sequence (using up their counts), then any remaining chars not in order.
class Solution {
public:
    string customSortString(string order, string s) {
        int cnt[26] = {0};
        for (char c : s) cnt[c-'a']++;
        string res;
        for (char c : order) {
            while (cnt[c-'a'] > 0) { res += c; cnt[c-'a']--; }
        }
        for (int i = 0; i < 26; i++) {
            while (cnt[i] > 0) { res += char('a'+i); cnt[i]--; }
        }
        return res;
    }
};
