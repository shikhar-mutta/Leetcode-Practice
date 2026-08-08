// Link: https://leetcode.com/problems/shortest-distance-to-a-character/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: two passes — left-to-right tracking distance since last occurrence of c, right-to-left doing the same, take the min at each position.
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> res(n, INT_MAX);
        int last = -n*2;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) last = i;
            res[i] = i - last;
        }
        last = n*2;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == c) last = i;
            res[i] = min(res[i], last - i);
        }
        return res;
    }
};
