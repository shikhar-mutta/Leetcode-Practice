// Link: https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOfSubstrings(string word, int k) {
        auto isVowel = [](char c) {
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
        };
        int n = word.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char,int> vowelCnt;
            int consonants = 0;
            for (int j = i; j < n; j++) {
                if (isVowel(word[j])) vowelCnt[word[j]]++;
                else consonants++;
                if (consonants > k) break;
                if ((int)vowelCnt.size() == 5 && consonants == k) cnt++;
            }
        }
        return cnt;
    }
};
