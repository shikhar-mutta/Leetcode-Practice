// Link: https://leetcode.com/problems/minimum-levels-to-gain-more-points/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        long long total = 0;
        for (int x : possible) total += (x ? 1 : -1);
        long long prefix = 0;
        for (int i = 0; i < n - 1; i++) {
            prefix += (possible[i] ? 1 : -1);
            if (prefix > total - prefix) return i + 1;
        }
        return -1;
    }
};
