// Link: https://leetcode.com/problems/merge-strings-alternately/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int i = 0, j = 0;
        while (i < (int)word1.size() || j < (int)word2.size()) {
            if (i < (int)word1.size()) res += word1[i++];
            if (j < (int)word2.size()) res += word2[j++];
        }
        return res;
    }
};
