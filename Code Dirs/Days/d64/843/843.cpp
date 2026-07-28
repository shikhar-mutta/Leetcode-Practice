// Link: https://leetcode.com/problems/guess-the-word/description/

#include <bits/stdc++.h>
using namespace std;

class Master {
    string secret;
    int guessesUsed = 0;
    int maxGuesses;
    bool solved = false;
public:
    Master(const string& secret, int maxGuesses = 10) : secret(secret), maxGuesses(maxGuesses) {}
    int guess(const string& word) {
        guessesUsed++;
        if (guessesUsed > maxGuesses) return -1;
        int c = 0;
        for (int i = 0; i < (int)word.size(); i++) if (word[i] == secret[i]) c++;
        if (c == (int)secret.size()) solved = true;
        return c;
    }
    bool wasSolved() const { return solved; }
};

// Added
// TC: O(guesses * n^2 * L)  SC: O(n)
// Approach: minimax candidate selection. On each round, for every
// remaining candidate word, compute how many other candidates share
// each possible match-count with it; pick the candidate whose worst-case
// group size is smallest (most discriminating guess). Guess it via
// master.guess(); if not fully matched, filter the candidate pool to
// only words sharing that same match count with the guess, and repeat.
class Solution {
    int matches(const string& a, const string& b) {
        int c = 0;
        for (int i = 0; i < (int)a.size(); i++) if (a[i] == b[i]) c++;
        return c;
    }
public:
    void findSecretWord(vector<string>& words, Master& master) {
        vector<string> candidates = words;
        for (int round = 0; round < 10 && !candidates.empty(); round++) {
            int bestIdx = 0, bestWorst = INT_MAX;
            for (int i = 0; i < (int)candidates.size(); i++) {
                int cnt[7] = {};
                for (int j = 0; j < (int)candidates.size(); j++) {
                    if (i == j) continue;
                    cnt[matches(candidates[i], candidates[j])]++;
                }
                int worst = *max_element(cnt, cnt + 7);
                if (worst < bestWorst) { bestWorst = worst; bestIdx = i; }
            }
            string guess = candidates[bestIdx];
            int m = master.guess(guess);
            if (m == (int)guess.size()) return;
            vector<string> next;
            for (auto& w : candidates) if (matches(guess, w) == m) next.push_back(w);
            candidates = next;
        }
    }
};
