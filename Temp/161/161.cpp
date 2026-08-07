// Link: https://leetcode.com/problems/one-edit-distance/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: if lengths differ by >1, false; if equal length, count mismatched chars must be exactly 1;
// if lengths differ by 1, walk both until first mismatch then check the rest of the longer matches the shorter
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.size(), m = t.size();
        if (abs(n - m) > 1) return false;
        if (n > m) { swap(s, t); swap(n, m); }
        int i = 0;
        while (i < n && s[i] == t[i]) i++;
        if (i == n) return n != m;
        if (n == m) return s.substr(i+1) == t.substr(i+1);
        return s.substr(i) == t.substr(i+1);
    }
};
