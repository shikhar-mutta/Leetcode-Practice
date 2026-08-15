// Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char c : word) freq[c - 'a']++;
        sort(freq.rbegin(), freq.rend());
        int total = 0;
        for (int i = 0; i < 26; i++) {
            int presses = i / 8 + 1;
            total += freq[i] * presses;
        }
        return total;
    }
};
