// Link: https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        string vowels = "aeiou";
        int n = word.size();
        int best = 0;
        int start = 0;
        int distinct = 1;
        for (int i = 1; i <= n; i++) {
            if (i < n && word[i] >= word[i-1]) {
                if (word[i] != word[i-1]) distinct++;
            } else {
                if (distinct == 5 && word[start] == 'a' && word[i-1] == 'u') {
                    best = max(best, i - start);
                }
                start = i;
                distinct = 1;
            }
        }
        return best;
    }
};
