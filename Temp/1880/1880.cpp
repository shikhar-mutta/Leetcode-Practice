// Link: https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int toNum(const string& w) {
        int num = 0;
        for (char c : w) num = num * 10 + (c - 'a');
        return num;
    }

    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return toNum(firstWord) + toNum(secondWord) == toNum(targetWord);
    }
};
