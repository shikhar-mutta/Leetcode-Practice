// Link: https://leetcode.com/problems/two-furthest-houses-with-different-colors/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int best = 0;
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                if (colors[i] != colors[j]) { best = max(best, j - i); break; }
            }
        }
        return best;
    }
};
