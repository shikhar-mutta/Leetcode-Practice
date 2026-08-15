// Link: https://leetcode.com/problems/number-of-ways-to-select-buildings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.size();
        long long totalZeros = count(s.begin(), s.end(), '0');
        long long totalOnes = n - totalZeros;
        long long zerosBefore = 0, onesBefore = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long zerosAfter = totalZeros - zerosBefore - (s[i] == '0' ? 1 : 0);
            long long onesAfter = totalOnes - onesBefore - (s[i] == '1' ? 1 : 0);
            if (s[i] == '1') {
                ans += zerosBefore * zerosAfter;
            } else {
                ans += onesBefore * onesAfter;
            }
            if (s[i] == '0') zerosBefore++;
            else onesBefore++;
        }
        return ans;
    }
};
