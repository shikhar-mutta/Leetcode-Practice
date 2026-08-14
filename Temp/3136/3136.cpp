// Link: https://leetcode.com/problems/valid-word/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;
        bool hasVowel = false, hasConsonant = false;
        for (char c : word) {
            if (isalpha(c)) {
                char lc = tolower(c);
                if (lc=='a'||lc=='e'||lc=='i'||lc=='o'||lc=='u') hasVowel = true;
                else hasConsonant = true;
            } else if (!isdigit(c)) {
                return false;
            }
        }
        return hasVowel && hasConsonant;
    }
};
