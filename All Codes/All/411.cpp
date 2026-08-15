// Link: https://leetcode.com/problems/minimum-unique-word-abbreviation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n * d)  SC: O(d)
// Approach: only same-length dictionary words matter; represent each as a
// bitmask of positions differing from target. Try every subset of "kept"
// positions in order of resulting abbreviation length, pick the first whose
// kept-set hits (intersects) every conflicting word's diff mask
class Solution {
    string abbreviate(const string& target, int keepMask) {
        string res;
        int n = target.size();
        int i = 0;
        while (i < n) {
            if (keepMask & (1 << i)) {
                res += target[i];
                i++;
            } else {
                int count = 0;
                while (i < n && !(keepMask & (1 << i))) { count++; i++; }
                res += to_string(count);
            }
        }
        return res;
    }

    int abbrevLength(const string& target, int keepMask) {
        int n = target.size();
        int len = 0, i = 0;
        while (i < n) {
            if (keepMask & (1 << i)) { len++; i++; }
            else {
                int count = 0;
                while (i < n && !(keepMask & (1 << i))) { count++; i++; }
                len += to_string(count).size();
            }
        }
        return len;
    }

public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        int n = target.size();
        vector<int> diffMasks;
        for (auto& w : dictionary) {
            if (w.size() != target.size()) continue;
            int mask = 0;
            for (int i = 0; i < n; i++) if (w[i] != target[i]) mask |= (1 << i);
            diffMasks.push_back(mask);
        }

        int bestMask = (1 << n) - 1; // keep everything as fallback
        int bestLen = abbrevLength(target, bestMask);

        for (int keepMask = 0; keepMask < (1 << n); keepMask++) {
            bool valid = true;
            for (int diff : diffMasks) {
                if ((keepMask & diff) == 0) { valid = false; break; }
            }
            if (!valid) continue;
            int len = abbrevLength(target, keepMask);
            if (len < bestLen) {
                bestLen = len;
                bestMask = keepMask;
            }
        }
        return abbreviate(target, bestMask);
    }
};
