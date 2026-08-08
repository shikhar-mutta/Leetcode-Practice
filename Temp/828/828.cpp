// Link: https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: for each occurrence of a char at index i, with previous occurrence at p (or -1) and next occurrence at nx (or n), it contributes uniquely to (i-p)*(nx-i) substrings. Sum this over all positions.
class Solution {
public:
    int uniqueLetterString(string s) {
        const long long MOD = 1e9+7;
        int n = s.size();
        vector<int> prev(n), next(n, n);
        vector<int> lastSeen(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i]-'A';
            prev[i] = lastSeen[c];
            lastSeen[c] = i;
        }
        vector<int> nextSeen(26, n);
        for (int i = n-1; i >= 0; i--) {
            int c = s[i]-'A';
            next[i] = nextSeen[c];
            nextSeen[c] = i;
        }
        long long total = 0;
        for (int i = 0; i < n; i++) {
            total = (total + (long long)(i - prev[i]) * (next[i] - i)) % MOD;
        }
        return (int)total;
    }
};
