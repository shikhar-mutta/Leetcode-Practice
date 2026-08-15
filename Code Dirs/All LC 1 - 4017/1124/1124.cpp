// Link: https://leetcode.com/problems/longest-well-performing-interval/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int,int> firstIdx;
        int score = 0, best = 0;
        for (int i = 0; i < (int)hours.size(); i++) {
            score += hours[i] > 8 ? 1 : -1;
            if (score > 0) {
                best = i + 1;
            } else {
                if (!firstIdx.count(score)) firstIdx[score] = i;
                if (firstIdx.count(score - 1)) best = max(best, i - firstIdx[score - 1]);
            }
        }
        return best;
    }
};
