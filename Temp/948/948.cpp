// Link: https://leetcode.com/problems/bag-of-tokens/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int lo = 0, hi = tokens.size() - 1;
        int score = 0, best = 0;
        while (lo <= hi) {
            if (power >= tokens[lo]) {
                power -= tokens[lo++];
                score++;
                best = max(best, score);
            } else if (score > 0 && lo < hi) {
                power += tokens[hi--];
                score--;
            } else {
                break;
            }
        }
        return best;
    }
};
