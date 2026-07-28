// Link: https://leetcode.com/problems/sum-of-scores-of-built-strings/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: score(i) is exactly the Z-function value z[i] (length of the
// longest common prefix of s and s[i:]), since it's the longest suffix
// starting at i matching a prefix of s. Sum z[] plus n for i=0.
class Solution {
public:
    long long sumScores(string s) {
        int n = s.size();
        vector<int> z(n, 0);
        z[0] = n;
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i < r) z[i] = min(r - i, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
            if (i + z[i] > r) { l = i; r = i + z[i]; }
        }
        long long sum = 0;
        for (int v : z) sum += v;
        return sum;
    }
};
