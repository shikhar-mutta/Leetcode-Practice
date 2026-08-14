// Link: https://leetcode.com/problems/first-letter-to-appear-twice/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> seen;
        for (char c : s) {
            if (seen.count(c)) return c;
            seen.insert(c);
        }
        return ' ';
    }
};
