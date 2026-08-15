// Link: https://leetcode.com/problems/last-substring-in-lexicographical-order/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lastSubstring(string s) {
        int n = s.size();
        int i = 0, j = 1, k = 0;
        while (j + k < n) {
            if (s[i+k] == s[j+k]) { k++; continue; }
            if (s[i+k] < s[j+k]) { i = max(i+k+1, j); j = i+1; }
            else { j = j+k+1; }
            k = 0;
        }
        return s.substr(i);
    }
};
