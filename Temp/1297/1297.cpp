// Link: https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string,int> freq;
        int n = s.size();
        for (int i = 0; i + minSize <= n; i++) {
            string sub = s.substr(i, minSize);
            unordered_set<char> distinct(sub.begin(), sub.end());
            if ((int)distinct.size() <= maxLetters) freq[sub]++;
        }
        int best = 0;
        for (auto& [k, v] : freq) best = max(best, v);
        return best;
    }
};
