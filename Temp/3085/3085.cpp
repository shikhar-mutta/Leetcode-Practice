// Link: https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for (char c : word) freq[c - 'a']++;
        vector<int> f;
        for (int x : freq) if (x > 0) f.push_back(x);

        int best = INT_MAX;
        for (int m : f) {
            int del = 0;
            for (int x : f) {
                if (x < m) del += x;
                else if (x > m + k) del += x - (m + k);
            }
            best = min(best, del);
        }
        return best;
    }
};
