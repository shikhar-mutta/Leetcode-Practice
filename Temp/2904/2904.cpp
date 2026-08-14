// Link: https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string best = "";
        int l = 0, ones = 0;
        for (int r = 0; r < n; r++) {
            if (s[r] == '1') ones++;
            while (ones > k) {
                if (s[l] == '1') ones--;
                l++;
            }
            while (l < r && s[l] == '0' && ones == k) l++;
            if (ones == k) {
                string cand = s.substr(l, r - l + 1);
                if (best.empty() || cand.size() < best.size() ||
                    (cand.size() == best.size() && cand < best)) {
                    best = cand;
                }
            }
        }
        return best;
    }
};
