// Link: https://leetcode.com/problems/find-special-substring-of-length-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.size();
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            int len = j - i;
            bool leftOk = (i == 0 || s[i - 1] != s[i]);
            bool rightOk = (j == n || s[j] != s[i]);
            if (len == k && leftOk && rightOk) return true;
            i = j;
        }
        return false;
    }
};
