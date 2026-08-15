// Link: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int count = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            int first = s.find(c);
            int last = s.rfind(c);
            if (first == -1 || first == last) continue;
            unordered_set<char> between(s.begin() + first + 1, s.begin() + last);
            count += between.size();
        }
        return count;
    }
};
