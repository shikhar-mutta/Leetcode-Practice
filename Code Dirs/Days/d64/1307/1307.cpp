// Link: https://leetcode.com/problems/verbal-arithmetic-puzzle/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(10! ) worst case, heavily pruned by column-wise carry checks  SC: O(letters)
// Approach: column-by-column DFS (from least significant digit),
// assigning digits only to the letters that appear in the current
// column and aren't yet assigned. Once a column's letters are all
// assigned, verify sum(word digits) + carryIn ≡ result digit (mod 10)
// and propagate the new carry to the next column. Leading letters of
// multi-character words/result can't be assigned 0.
class Solution {
    vector<string>* words;
    string* result;
    int maxLen;
    int assigned[26];
    bool usedDigit[10];
    bool isLeading[26];

    bool assignLetters(vector<char>& letters, int pos, int col, int carry) {
        if (pos == (int)letters.size()) return solveColumn(col + 1, computeCarry(col, carry));
        char c = letters[pos];
        if (assigned[c - 'A'] != -1) return assignLetters(letters, pos + 1, col, carry);
        for (int d = 0; d <= 9; d++) {
            if (usedDigit[d]) continue;
            if (d == 0 && isLeading[c - 'A']) continue;
            assigned[c - 'A'] = d;
            usedDigit[d] = true;
            if (assignLetters(letters, pos + 1, col, carry)) return true;
            usedDigit[d] = false;
            assigned[c - 'A'] = -1;
        }
        return false;
    }

    int computeCarry(int col, int carryIn) {
        int total = carryIn;
        for (auto& w : *words) {
            int idx = (int)w.size() - 1 - col;
            if (idx >= 0) total += assigned[w[idx] - 'A'];
        }
        int idx = (int)result->size() - 1 - col;
        int resDigit = (idx >= 0) ? assigned[(*result)[idx] - 'A'] : 0;
        if ((total - resDigit) % 10 != 0) return -1; // sentinel for failure
        return (total - resDigit) / 10;
    }

    bool solveColumn(int col, int carry) {
        if (carry == -1) return false; // propagated failure sentinel
        if (col == maxLen) return carry == 0;

        vector<char> colLetters;
        auto addIfNew = [&](char c) {
            if (find(colLetters.begin(), colLetters.end(), c) == colLetters.end()) colLetters.push_back(c);
        };
        for (auto& w : *words) {
            int idx = (int)w.size() - 1 - col;
            if (idx >= 0) addIfNew(w[idx]);
        }
        int idx = (int)result->size() - 1 - col;
        if (idx >= 0) addIfNew((*result)[idx]);

        return assignLetters(colLetters, 0, col, carry);
    }
public:
    bool isSolvable(vector<string>& words, string result) {
        this->words = &words;
        this->result = &result;
        fill(begin(assigned), end(assigned), -1);
        fill(begin(usedDigit), end(usedDigit), false);
        fill(begin(isLeading), end(isLeading), false);

        maxLen = result.size();
        for (auto& w : words) maxLen = max(maxLen, (int)w.size());

        for (auto& w : words) if (w.size() > 1) isLeading[w[0] - 'A'] = true;
        if (result.size() > 1) isLeading[result[0] - 'A'] = true;

        return solveColumn(0, 0);
    }
};
