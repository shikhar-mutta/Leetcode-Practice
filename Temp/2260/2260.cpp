// Link: https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> lastSeen;
        int best = INT_MAX;
        for (int i = 0; i < (int)cards.size(); i++) {
            if (lastSeen.count(cards[i])) {
                best = min(best, i - lastSeen[cards[i]] + 1);
            }
            lastSeen[cards[i]] = i;
        }
        return best == INT_MAX ? -1 : best;
    }
};
