// Link: https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        int freq[26] = {0};
        for (char c : s) freq[c - 'a']++;
        int maxOdd = INT_MIN, minEven = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            if (freq[i] % 2 == 1) maxOdd = max(maxOdd, freq[i]);
            else minEven = min(minEven, freq[i]);
        }
        return maxOdd - minEven;
    }
};
