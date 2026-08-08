// Link: https://leetcode.com/problems/reverse-prefix-of-word/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = word.find(ch);
        if (idx == -1) return word;
        reverse(word.begin(), word.begin() + idx + 1);
        return word;
    }
};
