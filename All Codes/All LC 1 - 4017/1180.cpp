// Link: https://leetcode.com/problems/count-substrings-with-only-one-distinct-letter/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countLetters(string s) {
        int n = s.size();
        long long total = 0;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            long long len = j - i;
            total += len * (len + 1) / 2;
            i = j;
        }
        return (int)total;
    }
};
