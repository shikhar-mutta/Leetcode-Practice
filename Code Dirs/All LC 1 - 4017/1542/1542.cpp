// Link: https://leetcode.com/problems/find-longest-awesome-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestAwesome(string s) {
        vector<int> firstSeen(1024, INT_MAX);
        firstSeen[0] = -1;
        int mask = 0, best = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            mask ^= (1 << (s[i] - '0'));
            if (firstSeen[mask] != INT_MAX) best = max(best, i - firstSeen[mask]);
            else firstSeen[mask] = i;
            for (int d = 0; d < 10; d++) {
                int m2 = mask ^ (1 << d);
                if (firstSeen[m2] != INT_MAX) best = max(best, i - firstSeen[m2]);
            }
        }
        return best;
    }
};
