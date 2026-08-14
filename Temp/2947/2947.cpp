// Link: https://leetcode.com/problems/count-beautiful-substrings-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }

    int beautifulSubstrings(string s, int k) {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int vowels = 0, consonants = 0;
            for (int j = i; j < n; j++) {
                if (isVowel(s[j])) vowels++; else consonants++;
                if (vowels == consonants && (long long)vowels * consonants % k == 0) cnt++;
            }
        }
        return cnt;
    }
};
