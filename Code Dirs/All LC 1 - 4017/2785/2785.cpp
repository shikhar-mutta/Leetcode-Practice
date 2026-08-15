// Link: https://leetcode.com/problems/sort-vowels-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }

    string sortVowels(string s) {
        vector<char> vowels;
        for (char c : s) if (isVowel(c)) vowels.push_back(c);
        sort(vowels.begin(), vowels.end());
        int idx = 0;
        for (char &c : s) if (isVowel(c)) c = vowels[idx++];
        return s;
    }
};
