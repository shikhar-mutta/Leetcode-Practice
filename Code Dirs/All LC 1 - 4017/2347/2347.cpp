// Link: https://leetcode.com/problems/best-poker-hand/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        bool flush = true;
        for (int i = 1; i < (int)suits.size(); i++) if (suits[i] != suits[0]) flush = false;
        if (flush) return "Flush";

        unordered_map<int,int> cnt;
        for (int r : ranks) cnt[r]++;
        int best = 0;
        for (auto& [k, c] : cnt) best = max(best, c);
        if (best >= 3) return "Three of a Kind";
        if (best == 2) return "Pair";
        return "High Card";
    }
};
