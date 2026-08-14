// Link: https://leetcode.com/problems/minimum-cost-to-make-all-characters-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(string s) {
        int n = s.size();
        long long total = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i-1]) {
                total += min(i, n - i);
            }
        }
        return total;
    }
};
