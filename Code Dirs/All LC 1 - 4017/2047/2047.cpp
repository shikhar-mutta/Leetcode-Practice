// Link: https://leetcode.com/problems/number-of-valid-words-in-a-sentence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(const string& w) {
        int hyphens = 0, puncts = 0;
        int n = w.size();
        for (int i = 0; i < n; i++) {
            char c = w[i];
            if (isdigit(c)) return false;
            if (c == '-') {
                hyphens++;
                if (hyphens > 1) return false;
                if (i == 0 || i == n - 1) return false;
                if (!islower(w[i - 1]) || !islower(w[i + 1])) return false;
            } else if (c == '!' || c == '.' || c == ',') {
                puncts++;
                if (puncts > 1) return false;
                if (i != n - 1) return false;
            } else if (!islower(c)) {
                return false;
            }
        }
        return true;
    }

    int countValidWords(string sentence) {
        stringstream ss(sentence);
        string word;
        int count = 0;
        while (ss >> word) {
            if (isValid(word)) count++;
        }
        return count;
    }
};
