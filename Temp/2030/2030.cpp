// Link: https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int n = s.size();
        vector<int> suf(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) suf[i] = suf[i + 1] + (s[i] == letter);

        string stk;
        int lettersInStack = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            while (!stk.empty() && stk.back() > c) {
                bool topIsLetter = (stk.back() == letter);
                int newSize = (int)stk.size() - 1;
                int newLettersInStack = lettersInStack - (topIsLetter ? 1 : 0);
                int neededAfterPop = max(0, repetition - newLettersInStack);
                if ((n - i) >= (k - newSize) && suf[i] >= neededAfterPop) {
                    stk.pop_back();
                    lettersInStack = newLettersInStack;
                } else break;
            }
            if ((int)stk.size() < k) {
                if (c == letter) {
                    stk.push_back(c);
                    lettersInStack++;
                } else {
                    int sizeAfter = (int)stk.size() + 1;
                    int capacityAfter = k - sizeAfter;
                    int neededNow = max(0, repetition - lettersInStack);
                    if (capacityAfter >= neededNow && suf[i + 1] >= neededNow && (n - i - 1) >= (k - sizeAfter)) {
                        stk.push_back(c);
                    }
                }
            }
        }
        return stk;
    }
};
