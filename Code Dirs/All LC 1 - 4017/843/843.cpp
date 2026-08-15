// Link: https://leetcode.com/problems/guess-the-word/description/

#include <bits/stdc++.h>
using namespace std;

class Master {
    string secret;
    int guessesUsed = 0;
    int maxGuesses;
    bool solved = false;
public:
    Master(string secret_, int maxGuesses_) : secret(secret_), maxGuesses(maxGuesses_) {}
    int guess(string word) {
        guessesUsed++;
        int matches = 0;
        for (int i = 0; i < (int)word.size(); i++)
            if (word[i] == secret[i]) matches++;
        if (matches == (int)secret.size()) solved = true;
        return matches;
    }
    bool success() const { return solved && guessesUsed <= maxGuesses; }
};

class Solution {
public:
    int matchCount(const string& a, const string& b) {
        int c = 0;
        for (int i = 0; i < (int)a.size(); i++) if (a[i] == b[i]) c++;
        return c;
    }
    void findSecretWord(vector<string>& words, Master& master) {
        vector<string> candidates = words;
        for (int round = 0; round < 10 && candidates.size() > 1; round++) {
            string guessWord = candidates[0];
            int matches = master.guess(guessWord);
            if (matches == (int)guessWord.size()) return;
            vector<string> next;
            for (auto& w : candidates)
                if (matchCount(w, guessWord) == matches) next.push_back(w);
            candidates = next;
        }
        if (!candidates.empty()) master.guess(candidates[0]);
    }
};
