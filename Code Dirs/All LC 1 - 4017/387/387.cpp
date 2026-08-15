// Link: https://leetcode.com/problems/first-unique-character-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1) (26 letters)
// Approach: count frequencies, scan for first char with count 1
class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};
        for (char c : s) count[c - 'a']++;
        for (int i = 0; i < (int)s.size(); i++) {
            if (count[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
