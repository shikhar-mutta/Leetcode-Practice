// Link: https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }

    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        for (int i = left; i <= right; i++) {
            if (isVowel(words[i].front()) && isVowel(words[i].back())) count++;
        }
        return count;
    }
};
