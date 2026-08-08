// Link: https://leetcode.com/problems/hand-of-straights/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        map<int,int> cnt;
        for (int x : hand) cnt[x]++;
        while (!cnt.empty()) {
            int start = cnt.begin()->first;
            for (int v = start; v < start + groupSize; v++) {
                auto it = cnt.find(v);
                if (it == cnt.end()) return false;
                if (--it->second == 0) cnt.erase(it);
            }
        }
        return true;
    }
};
