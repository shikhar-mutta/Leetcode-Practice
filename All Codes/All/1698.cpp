// Link: https://leetcode.com/problems/number-of-distinct-substrings-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDistinct(string s) {
        unordered_set<string> seen;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                seen.insert(s.substr(i, j - i + 1));
            }
        }
        return (int)seen.size();
    }
};
