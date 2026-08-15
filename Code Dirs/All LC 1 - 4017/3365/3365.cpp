// Link: https://leetcode.com/problems/rearrange-k-substrings-to-form-target-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        if (n % k != 0) return false;
        int chunkLen = n / k;
        multiset<string> sChunks, tChunks;
        for (int i = 0; i < n; i += chunkLen) {
            sChunks.insert(s.substr(i, chunkLen));
            tChunks.insert(t.substr(i, chunkLen));
        }
        return sChunks == tChunks;
    }
};
