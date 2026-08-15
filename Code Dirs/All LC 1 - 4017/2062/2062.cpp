// Link: https://leetcode.com/problems/count-vowel-substrings-of-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countVowelSubstrings(string word) {
        string vowels = "aeiou";
        int n = word.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string sub = word.substr(i, j - i + 1);
                bool ok = true;
                for (char c : sub) if (vowels.find(c) == string::npos) { ok = false; break; }
                if (!ok) continue;
                set<char> s(sub.begin(), sub.end());
                if (s.size() == 5) count++;
            }
        }
        return count;
    }
};
