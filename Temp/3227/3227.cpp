// Link: https://leetcode.com/problems/vowels-game-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        auto isVowel = [](char c) {
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
        };
        for (char c : s) if (isVowel(c)) return true;
        return false;
    }
};
