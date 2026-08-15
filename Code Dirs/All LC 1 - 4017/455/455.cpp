// Link: https://leetcode.com/problems/assign-cookies/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(1)
// Approach: sort both arrays, greedily match smallest cookie that
// satisfies the smallest unmatched child's greed
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        while (i < (int)g.size() && j < (int)s.size()) {
            if (s[j] >= g[i]) i++;
            j++;
        }
        return i;
    }
};
