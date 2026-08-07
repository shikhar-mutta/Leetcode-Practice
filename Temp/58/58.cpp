// Link: https://leetcode.com/problems/length-of-last-word/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: skip trailing spaces, then count backward until the next space or string start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' ') i--;
        int len = 0;
        while (i >= 0 && s[i] != ' ') { len++; i--; }
        return len;
    }
};
