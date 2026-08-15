// Link: https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int best = 0;
        for (auto& s : sentences) {
            int spaces = count(s.begin(), s.end(), ' ');
            best = max(best, spaces + 1);
        }
        return best;
    }
};
