// Link: https://leetcode.com/problems/reverse-vowels-of-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: two-pointer, swap vowels found from both ends
class Solution {
    bool isVowel(char c) {
        c = tolower(c);
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }

public:
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (!isVowel(s[l])) { l++; continue; }
            if (!isVowel(s[r])) { r--; continue; }
            swap(s[l++], s[r--]);
        }
        return s;
    }
};
