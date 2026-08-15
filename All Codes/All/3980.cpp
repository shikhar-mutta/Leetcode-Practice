// Link: https://leetcode.com/problems/minimum-operations-to-transform-binary-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        if (n == 1) {
            if (s1[0] == s2[0]) return 0;
            return (s1[0] == '0') ? 1 : -1;
        }
        long long ans = 0;
        int leftover = 0;
        int i = 0;
        while (i < n) {
            if (s1[i] == '1' && s2[i] == '0') {
                int j = i;
                while (j < n && s1[j] == '1' && s2[j] == '0') j++;
                int L = j - i;
                ans += L / 2;
                if (L % 2) leftover++;
                i = j;
            } else {
                if (s1[i] == '0' && s2[i] == '1') ans++;
                i++;
            }
        }
        ans += (long long)leftover * 2;
        return (int)ans;
    }
};
