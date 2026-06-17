// Link: https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        // map each word to a number: letter 'a'..'j' -> digit 0..9
        auto val = [](const string& w) {
            long long n = 0;
            for (char c : w) n = n * 10 + (c - 'a');
            return n;
        };
        return val(firstWord) + val(secondWord) == val(targetWord);
    }
};
