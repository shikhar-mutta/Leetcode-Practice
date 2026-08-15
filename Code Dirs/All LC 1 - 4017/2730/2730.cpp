// Link: https://leetcode.com/problems/find-the-longest-semi-repetitive-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.size();
        int left = 0, adjCount = 0, best = 1;
        for (int right = 1; right < n; right++) {
            if (s[right] == s[right-1]) adjCount++;
            while (adjCount > 1) {
                if (s[left] == s[left+1]) adjCount--;
                left++;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
