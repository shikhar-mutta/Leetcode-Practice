// Link: https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;
        string vowels = "aeiou";
        int maxVowel = 0, maxCons = 0;
        for (int c = 0; c < 26; c++) {
            bool isVowel = vowels.find('a' + c) != string::npos;
            if (isVowel) maxVowel = max(maxVowel, cnt[c]);
            else maxCons = max(maxCons, cnt[c]);
        }
        return maxVowel + maxCons;
    }
};
