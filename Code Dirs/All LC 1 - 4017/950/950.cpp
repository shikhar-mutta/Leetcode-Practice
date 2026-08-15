// Link: https://leetcode.com/problems/reveal-cards-in-increasing-order/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        deque<int> idx;
        for (int i = 0; i < n; i++) idx.push_back(i);
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[idx.front()] = deck[i];
            idx.pop_front();
            if (!idx.empty()) {
                idx.push_back(idx.front());
                idx.pop_front();
            }
        }
        return res;
    }
};
