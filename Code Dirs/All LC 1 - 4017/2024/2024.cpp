// Link: https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestWithFlip(const string& s, int k, char target) {
        int left = 0, count = 0, best = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            if (s[right] != target) count++;
            while (count > k) {
                if (s[left] != target) count--;
                left++;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(longestWithFlip(answerKey, k, 'T'), longestWithFlip(answerKey, k, 'F'));
    }
};
