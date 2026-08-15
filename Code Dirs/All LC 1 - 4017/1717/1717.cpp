// Link: https://leetcode.com/problems/maximum-score-from-removing-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char high = x >= y ? 'a' : 'b';
        int highScore = max(x, y), lowScore = min(x, y);
        char firstH = high, secondH = (high == 'a') ? 'b' : 'a';
        int total = 0;

        string stack;
        for (char c : s) {
            if (!stack.empty() && stack.back() == firstH && c == secondH) {
                stack.pop_back();
                total += highScore;
            } else {
                stack += c;
            }
        }

        string stack2;
        for (char c : stack) {
            if (!stack2.empty() && stack2.back() == secondH && c == firstH) {
                stack2.pop_back();
                total += lowScore;
            } else {
                stack2 += c;
            }
        }

        return total;
    }
};
