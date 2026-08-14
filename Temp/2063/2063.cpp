// Link: https://leetcode.com/problems/vowels-of-all-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countVowels(string word) {
        string vowels = "aeiou";
        int n = word.size();
        long long total = 0;
        for (int i = 0; i < n; i++) {
            if (vowels.find(word[i]) != string::npos) {
                total += (long long)(i + 1) * (n - i);
            }
        }
        return total;
    }
};
