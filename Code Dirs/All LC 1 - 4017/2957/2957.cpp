// Link: https://leetcode.com/problems/remove-adjacent-almost-equal-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int n = word.size();
        int ops = 0;
        int i = 1;
        while (i < n) {
            if (abs(word[i] - word[i-1]) <= 1) {
                ops++;
                i += 2;
            } else {
                i++;
            }
        }
        return ops;
    }
};
