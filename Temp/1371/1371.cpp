// Link: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char,int> bit = {{'a',0},{'e',1},{'i',2},{'o',3},{'u',4}};
        vector<int> firstSeen(32, -2);
        firstSeen[0] = -1;
        int mask = 0, best = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (bit.count(s[i])) mask ^= (1 << bit[s[i]]);
            if (firstSeen[mask] == -2) firstSeen[mask] = i;
            else best = max(best, i - firstSeen[mask]);
        }
        return best;
    }
};
