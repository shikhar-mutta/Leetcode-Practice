// Link: https://leetcode.com/problems/verbal-arithmetic-puzzle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<char,int> coeff;
    unordered_set<char> leadingChars;
    vector<char> letters;
    bool usedDigit[10] = {false};

    bool dfs(int idx, long long sum) {
        if (idx == (int)letters.size()) return sum == 0;
        char c = letters[idx];
        for (int d = 0; d <= 9; d++) {
            if (usedDigit[d]) continue;
            if (d == 0 && leadingChars.count(c)) continue;
            usedDigit[d] = true;
            if (dfs(idx + 1, sum + (long long)coeff[c] * d)) { usedDigit[d] = false; return true; }
            usedDigit[d] = false;
        }
        return false;
    }

    bool isSolvable(vector<string>& words, string result) {
        for (auto& w : words) {
            int mult = 1;
            for (int i = (int)w.size() - 1; i >= 0; i--) {
                coeff[w[i]] += mult;
                mult *= 10;
            }
            if (w.size() > 1) leadingChars.insert(w[0]);
        }
        int mult = 1;
        for (int i = (int)result.size() - 1; i >= 0; i--) {
            coeff[result[i]] -= mult;
            mult *= 10;
        }
        if (result.size() > 1) leadingChars.insert(result[0]);

        if ((int)coeff.size() > 10) return false;

        for (auto& [c, _] : coeff) letters.push_back(c);
        sort(letters.begin(), letters.end(), [&](char a, char b) {
            return abs(coeff[a]) > abs(coeff[b]);
        });

        return dfs(0, 0);
    }
};
